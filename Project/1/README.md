# Project 1 — Password strength meter

*Spec no longer available; the header comment in [`passmeter.c`](passmeter.c) is the surviving
statement of it. [CS221 Drive](https://drive.google.com/drive/folders/1y2qJ_GMT6mwkcMrQ_NudOBzD-ISYlIAE)*

Scores a password's strength and generates a default one. The first project, and the one that
establishes the course's security framing.

## Concepts

**Substring search, written by hand.** `contains_username` is a nested double loop — for each
starting offset in the password, compare characters against the username — with `tolower` on both
sides for case-insensitive matching. It is *O(nm)*, which is fine at these sizes, and writing it out
rather than calling `strstr` is the point: you are meant to see that "does A contain B" is a loop,
and that the outer bound is `pass_len - user_len` rather than `pass_len`. Getting that bound wrong is
the classic off-by-one that reads past the buffer.

**Character classification via `<ctype.h>`.** `isupper`, `islower`, `isdigit`, `ispunct` are the
building blocks for the strength rules. Worth knowing these exist rather than writing `c >= 'a' &&
c <= 'z'` — they are locale-aware and communicate intent.

**`const char *` in the signature.** `contains_username (const char *username, const char *password)`
promises not to modify either string. In C the compiler enforces this, and it is the cheapest form of
documentation available — a reader knows immediately that this function only inspects.

**Why the username check matters at all.** A password containing the username is weak regardless of
length or character variety, because it is exactly what a targeted attacker tries first. That the
project makes this a *first-class rule* rather than an afterthought is the security lesson.

**Random generation needs seeding.** The generator uses `time.h` — `srand(time(NULL))` — because
`rand()` without seeding produces the same sequence every run. That is a genuine security bug in a
password generator, and a useful reminder that `rand()` is not cryptographically secure regardless;
real key material comes from the OS.

## Re-learning path

`contains_username` first (the bounds), then the strength scoring, then the generator.
[`status.txt`](status.txt) is Ryan's submitted self-assessment.
