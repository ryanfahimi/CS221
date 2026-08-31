# Project 2 — `rgrep`, a restricted regex matcher

*Spec no longer available; the header comments in the source are the surviving statement of it.
[CS221 Drive](https://drive.google.com/drive/folders/1y2qJ_GMT6mwkcMrQ_NudOBzD-ISYlIAE)*

A cut-down `grep`: read lines from stdin, print the ones matching a pattern. The pattern language
supports literal characters, `.` (any character), `+` (one or more), `?` (zero or one), and `\` to
escape a metacharacter.

## The shape of the project

[`rgrep.c`](rgrep.c) and [`matcher.h`](matcher.h) are both marked **"You must not change this
file."** All the work happens in [`matcher.c`](matcher.c) behind one declared function:

```c
int rgrep_matches(char *line, char *pattern);
```

That constraint is the most instructive thing here. The driver already handles the loop, the 4096-byte
buffer, `feof`/`ferror` checking, and `perror` on failure — so the exercise is *purely* the matching
logic, and the interface cannot be bent to make it easier.

## Concepts

**Pattern matching is two cursors advancing at different rates.** The core idea: walk a pointer
through the line and a pointer through the pattern, and decide at each step how far each moves.
A literal advances both by one. A `.` advances both by one without comparing. A `?` or `+` advances
the *pattern* by two (the character plus the metacharacter — hence `STEP_OVER_CHAR 2`) while
advancing the line by a variable amount.

**Pointer-to-pointer for mutable cursors.** `handle_optional_char (char **partial_line, char
**pattern)` takes `char **` because it must move the *caller's* pointers, not copies. This is the
C idiom for an out-parameter, and it is exactly the reference lesson from
[CS112's Lab07](https://github.com/ryanfahimi/CS112) with the indirection made syntactically
visible: `*pattern += STEP_OVER_CHAR` modifies the caller's variable, `pattern += 2` would not.

**`?` and `+` differ in one place.** `handle_optional_char` consumes the line character *if it
matches*, then moves past the pattern regardless — zero or one. `handle_repeatable_char` loops
`while (**partial_line && **partial_line == **pattern)` — one or more. Reading them side by side is
the clearest statement of what those two quantifiers mean.

**Named constants over magic characters.** `#define PERIOD '.'`, `PLUS_SIGN`, `QUESTION_MARK`,
`BACKSLASH`, `NULL_TERMINATOR`. Verbose, but it makes the matching logic read as rules rather than
character comparisons.

**Escaping needs a lookahead.** A `\` means the *next* pattern character is a literal, which requires
peeking one ahead and then advancing two. It is where most implementations break — particularly the
edge case of a trailing backslash with nothing after it.

**Where this genuinely stops short.** This matcher is a linear scan, not a backtracking engine. Real
regex requires trying alternatives and undoing — which is why proper implementations use a state
machine or recursion with backtracking. Worth knowing this is the simplified version, and worth
re-deriving *which* patterns it would get wrong.

## Running

```bash
make
./rgrep 'ab+c' < input.txt
```

[`input.txt`](input.txt) is the sample data; [`status.txt`](status.txt) is Ryan's submitted
self-assessment.
