# Labs

Weekly labs, numbered 2–14 by week. Files are mostly numbered by problem (`1.c`, `2.c`), sometimes
nested a level deeper when a lab had parts. Lab material is in Drive under `Lab/`, and the lecture
decks (`2.pdf`–`26.pdf`) are the companion reading:
[CS221 Drive](https://drive.google.com/drive/folders/1y2qJ_GMT6mwkcMrQ_NudOBzD-ISYlIAE).

**The lab prompts themselves are gone** — see the [root README](../README.md). What follows
reconstructs each lab's subject from the code.

| Lab | Subject |
|---|---|
| [2](2/)–[4](4/) | C basics: syntax, types, control flow, functions |
| [5](5/)–[6](6/) | Pointers, arrays, and strings |
| [7](7/) | Two-part lab; structs and memory |
| [8](8/)–[9](9/) | Continued pointer and memory work |
| [10](10/) | `make` and build structure — the only lab with a `Makefile` |
| [11](11/) | **Debugging with `gdb`** |
| [12](12/) | **File I/O and password hashing** |
| [13](13/) | **Bitwise operations; linked-list debugging** |
| [14](14/) | Bounds checking and defensive coding |

## Highlights

**[Lab 11](11/) — `gdb`, and code written to fail.**
[`example.c`](11/1/example.c) is the point of the lab, and it is worth reading closely:

```c
const int data[5] = { 1, 2, 3, 4, 5 };
int i, sum;
for (i = 0; i >= 0; ++i)
    sum += data[i];
```

Two bugs, deliberately. `sum` is **uninitialized**, so the accumulation starts from whatever was on
the stack. And the loop condition is `i >= 0`, which is true for every non-negative `i` — so it runs
past the end of a five-element array, reading arbitrary memory, until `i` overflows to negative
(itself undefined behaviour) or the program segfaults. Neither bug produces a compiler error. That is
the lab's argument for needing a debugger: the program is wrong in ways that only a running-state
inspection reveals. `7.c`/`8.c` come with matching `.txt` files — presumably the recorded `gdb`
sessions.

**[Lab 12](12/) — password storage done properly.**
[`labFileIO.c`](12/2/labFileIO.c) defines a `struct user` with `username`, `password[256]`,
`firstname`, `lastname`, **`salt[10]`**, and an `admin` flag, and hashes via
`crypt (password, "00")`. Three ideas in one file: passwords are stored **hashed, never in
plaintext**; a **salt** makes identical passwords hash differently, defeating precomputed rainbow
tables; and the record is serialized to a [`credential_file`](12/2/credential_file), so the file
format is part of the security design. The hard-coded `"00"` salt is a teaching simplification — a
real salt is random and per-user, and stored alongside the hash, which is why the struct has a field
for it. `#define _GNU_SOURCE` is required to get `crypt` from `unistd.h`.

**[Lab 13](13/) — bitmaps, and a bug hunt.** Part 1's
[`BitwiseOp_lab.c`](13/1/BitwiseOp_lab.c) replaces three `bool` permission fields (`write`, `read`,
`execute`) with a single `typedef unsigned char bitmap8`. The two `struct`s sit in the same file for
comparison — the `bool` version costs three bytes plus padding and can only ever hold three flags,
while the bitmap holds eight in one byte and supports set, clear, and test through `|`, `&~`, and
`&`. That is exactly how UNIX file permissions work.

Part 2 is linked-list debugging on a `userInfo` struct.
[`ll_cycle.c`](13/2/ll_cycle.c) is **Floyd's tortoise and hare**: `trav1` advances one node,
`trav2` two, and if a cycle exists they must eventually meet — *O(n)* time in *O(1)* space, versus the
obvious solution of remembering every visited node. [`ll_equal.c`](13/2/ll_equal.c) carries the
comment `/* FIXME: this function is buggy. */`, which is the assignment: find and fix it. Worth
re-reading with fresh eyes — the interesting failure modes are lists of different lengths and the
`NULL` handling at the end of the loop.

**[Lab 14](14/) — bounds checking as a habit.**
[`1.c`](14/1/1.c)'s `setValue` guards `index >= 0 && index < len` before writing. Trivial code, but it
is the course's summary position: C will not check this for you, the caller may not have, and an
unchecked write to `arr[index]` is how buffer overflows happen. Note the function must be *told* the
length — an array parameter has already decayed to a pointer and `sizeof` would give the pointer's
size.
