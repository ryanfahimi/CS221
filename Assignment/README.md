# Assignments

Assignments 1–4, with each problem as a numbered `.c` file. Some problems have lettered parts in
their own subdirectory (`2/3/a.c` … `e.c`, `2/5/a.c` … `c.c`), which usually signals a set of small
variations on one idea — the same program written several ways to show a difference.

**The assignment prompts are gone** — see the [root README](../README.md). The files are
self-contained programs, so each one still runs and can be read for what it does, but the *question*
it answered is not recoverable. Read them as worked examples rather than as solutions.

| Assignment | Files | Position in the course |
|---|---|---|
| [1](1/) | `2.c`–`6.c` | Early C — syntax, types, control flow. Numbering starts at 2, so problem 1 was likely written rather than coded. |
| [2](2/) | `1.c`, `2.c`, `3/a–e.c`, `4.c`, `5/a–c.c`, `6.c` | The largest, with two multi-part problems. Pointers and arrays. |
| [3](3/) | `1.c`–`5.c` | Memory, structs, strings. |
| [4](4/) | `3.c`, `4.c` | Only two files; late-semester material (processes, threads, or secure coding). |

For the concepts these exercise, the [labs](../Lab/) are better documented — they have more
surviving context — and the lecture decks in Drive (`2.pdf`–`26.pdf`) are the authoritative source.

Compile any of them directly:

```bash
gcc -g -Wall -o out Assignment/2/4.c && ./out
```
