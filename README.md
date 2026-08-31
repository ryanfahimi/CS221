# CS 221 — C and Systems Programming

**University of San Francisco · Fall 2023 · Prof. Vahab Pournaghshband**
Course materials (lecture slides 2–26, lab material, exams):
[**CS221 Google Drive folder**](https://drive.google.com/drive/folders/1y2qJ_GMT6mwkcMrQ_NudOBzD-ISYlIAE)

## What this course actually taught

C, and the machine underneath it. After two semesters of languages that manage memory for you, this
is the course where you manage it yourself and find out what that costs. The material splits into
three strands that keep re-crossing:

**The language and its dangers.** Pointers, arrays as pointers, manual allocation, string handling
without a string type, structs, and bitwise operations. Most of the assignments are small because
the difficulty is not algorithmic — it is that C will happily let you write past the end of an array
and keep running.

**The UNIX environment.** `make`, `gdb`, file I/O through both the C library and system calls,
command-line tools, and processes and threads. The course ran on USF's VMs and graded against
environment-matched test cases, so "works on my machine" was not available as a defence.

**Secure and defensive programming.** This is what makes the course distinctive, and it is woven
through rather than bolted on. Buffer overflows, input validation, password strength and hashing with
salts, permission bitmaps — the labs keep returning to a `struct user` with a username and password
field, and keep asking what an attacker could do with it.

The four projects are the spine: a password strength meter, a restricted `grep`, a climate-data
analyzer over multi-megabyte files, and a sorted doubly linked list. Each one is a complete program
with a specification to meet exactly, and each ships a `status.txt` — a short self-assessment Ryan
wrote on submission, which is a nice record of what he thought was done and what was left rough.

## Repo layout

| Folder | Contents |
|---|---|
| [`Lab/`](Lab/) | Labs 2–14, numbered by week. Mostly short, numbered `.c` files. |
| [`Assignment/`](Assignment/) | Assignments 1–4, problems numbered within each. |
| [`Project/`](Project/) | The four projects — the substantial work. |
| [`Exam/`](Exam/) | The final's coding portion. |

Each has its own README with the study-guide layer; the four projects have one each.

## Style note

The code follows **GNU style** — return type on its own line, function name at column zero, opening
brace on its own line, two-space indentation, space before the argument parenthesis. It looks unusual
next to K&R or Java-influenced C. It was a graded requirement, and the `status.txt` files mention
adherence to it explicitly.

## A gap worth knowing about

The assignment, project, and lab **specifications no longer exist anywhere accessible**. The course
site (`cs221v.cs.usfca.edu`) was USF-internal; the Internet Archive captured only its Fall 2023
announcements page and shell. Lecture 1 is also missing — Drive has decks `2.pdf` through `26.pdf`
only.

The practical consequence: for most of this repo, **the code is the only surviving statement of what
was asked**. Where a file only makes sense given its prompt, these READMEs reconstruct the prompt
from the code and say so. The projects are the exception — their headers quote the specification
directly, which is why they are documented in the most detail.

## Building

Most files are single-translation-unit programs:

```bash
gcc -g -Wall -o passmeter Project/1/passmeter.c
```

Projects 2 and 3 and one lab ship a `Makefile` — use `make` in those directories.
