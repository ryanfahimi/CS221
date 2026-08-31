# Project 3 — Climate data analysis

*Spec no longer available; the header comment in [`climate.c`](climate.c) preserves the required
output format verbatim.
[CS221 Drive](https://drive.google.com/drive/folders/1y2qJ_GMT6mwkcMrQ_NudOBzD-ISYlIAE)*

Reads one or more tab-delimited NOAA climate files and prints a per-state summary: record count,
average humidity and temperature, min and max temperature with the timestamps they occurred at,
lightning strikes, snow-cover records, and average cloud cover.

## Concepts

**Streaming aggregation, not storage.** The input files hold tens of thousands of records
(the header's example shows 17,097 for Tennessee and 48,357 for Washington), and the program never
holds them. `analyze_file` reads one line at a time and folds it into a running
`struct climate_info` per state — sums and counts for the averages, running extremes for min and max.
This is the project's real lesson: **an average does not require the data, only a sum and a count.**
Memory stays constant regardless of input size, and adding a fifth file costs nothing.

**A sparse array indexed by discovery order.** `struct climate_info *states[NUM_STATES]` is an array
of 50 *pointers*, initialized to `NULL`. A state's struct is allocated only when its code is first
seen — `create_climate` on miss, lookup on hit. So the array is fixed-size but the allocation is
demand-driven, and iterating it means skipping `NULL` entries. That is a common C pattern for "at most
N of something, unknown which."

**One owner, one `free`.** `free_states` walks the array and frees each non-`NULL` entry, and is
called both at the end of `main` and on the error path inside `create_climate`. Cleaning up on the
*failure* path is the part people forget, and it is what separates a program that leaks under stress
from one that doesn't.

**Aggregating across files, not per file.** Multiple filenames on the command line all fold into the
same `states` array, so a state appearing in two files accumulates across both. That is why the
struct array lives in `main` and is passed in, rather than being created inside `analyze_file`.

**Parsing tab-delimited records.** Fields are split on tabs and converted with `atof`/`atoi` or
`strtod`. Two things to notice: the timestamp arrives as a Unix epoch value and has to be rendered
with `ctime` to produce `Mon Aug 3 11:00:00 2015`, and any malformed line must be skipped rather than
allowed to corrupt the totals.

**Two spellings of the same parameter.** The declarations use `struct climate_info *states[]` and the
definition of `analyze_file` uses `struct climate_info **states`. These are identical in C — an array
parameter decays to a pointer — and seeing both in one file is a good reminder that C has no array
parameters at all.

## Running

```bash
make
./climate data_tn.tdv data_wa.tdv
```

The `.tdv` data files are not in the repo (they are large); the expected output format is in the
header comment. [`status.txt`](status.txt) is Ryan's submitted self-assessment.
