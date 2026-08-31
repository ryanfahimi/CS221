# Projects

The four graded projects. Each is a complete program written to an exact output specification, and
each carries a `status.txt` — Ryan's submitted self-assessment. Since the project specs are no longer
available anywhere (see the [root README](../README.md)), the header comment at the top of each
`.c` file is the best surviving statement of what was required; several quote the expected output
verbatim.

| Project | Program | Subject |
|---|---|---|
| [1](1/) | [`passmeter.c`](1/passmeter.c) | Password strength meter and generator |
| [2](2/) | [`matcher.c`](2/matcher.c) | `rgrep` — a restricted regular-expression matcher |
| [3](3/) | [`climate.c`](3/climate.c) | Aggregating multi-file NOAA climate data |
| [4](4/) | [`doubly_linked_list.c`](4/doubly_linked_list.c) | Sorted doubly linked list of strings |

## The arc

Projects 1 and 2 are **string processing under constraints** — no library shortcuts, careful
bounds handling. Project 3 is about **scale and aggregation**: parsing tens of thousands of
tab-delimited records across several files and producing one summary per state, where the challenge
is streaming rather than storing. Project 4 is **manual memory management** at its purest — a
doubly linked list where every insert allocates, every delete frees, and the whole thing must be
torn down cleanly.

A pattern across all four: the interface is fixed and the implementation is yours. Project 2 makes
this explicit — [`rgrep.c`](2/rgrep.c) and [`matcher.h`](2/matcher.h) are both marked *you must not
change this file*, and all the work happens behind a single declared function. That is the same
"program to an interface" idea from [CS112](https://github.com/ryanfahimi/CS112), enforced by the
build rather than by a type system.
