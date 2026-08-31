# Project 4 — Sorted doubly linked list

*Spec no longer available; the header comment in
[`doubly_linked_list.c`](doubly_linked_list.c) preserves it.
[CS221 Drive](https://drive.google.com/drive/folders/1y2qJ_GMT6mwkcMrQ_NudOBzD-ISYlIAE)*

A doubly linked list of strings kept in alphabetical order, driven by single-character commands read
from stdin (`i` + string to insert, `p` to print, `m` for member, `d` to delete, `f` to free). The
final project, and the purest manual-memory exercise in the course.

## Concepts

**Two allocations per node, and both must be freed.** `Allocate_node` mallocs the
`struct list_node_s` *and* separately mallocs `node_p->data` for the string. A node therefore owns a
second heap block, and `Free_node` has to release both — freeing the node without freeing its data
leaks the string silently. This is the ownership question that dominates C: **who allocated it, and
who is responsible for releasing it?**

**Doubly linked means four pointers change per operation.** The list keeps both a head `h_p` and a
tail `t_p`. Inserting between two nodes updates the new node's `prev_p` and `next_p` plus the
neighbours' pointers pointing back at it. The cases that break implementations are the boundaries:
inserting at the head, at the tail, into an empty list, and deleting the only node — each requires
updating `h_p` or `t_p` rather than a neighbour. Enumerating those cases *before* writing the code is
the technique.

**Sorted insertion is a `strcmp` walk.** `Insert` advances `curr_p` while the current string sorts
before the new one, then splices in ahead of it. Keeping the invariant on insert means `Member` can
stop early on overshoot and `Print` needs no sorting. Per [`status.txt`](status.txt), duplicates are
rejected — so `strcmp == 0` is a distinct case from `< 0` and `> 0`.

**Strings must be copied, not aliased.** The input buffer is reused for every command, so a node that
stored the buffer pointer would see its contents change on the next read. Hence the second `malloc`
plus `strcpy` into it. `STRING_MAX 100` bounds the copy — 99 characters plus the terminator.

**`Free_list` is the teardown discipline.** Walking a list while freeing it requires saving `next_p`
*before* the `free`, since reading a freed node is undefined behaviour that usually appears to work.
That trap is why this operation is a graded part of the assignment rather than an afterthought.

**No new headers allowed.** The comment says so explicitly: `stdio.h`, `stdlib.h`, `string.h`, and
nothing else. The constraint blocks any workaround and forces the pointer manipulation to be done by
hand.

**`Print_node (char title[], ...)`** is a debugging aid — labelled dumps of a single node. Building
your own inspection helper is the C equivalent of a debugger watch expression, and worth the fifteen
lines.

## Running

```bash
gcc -g -Wall -o doubly_linked_list doubly_linked_list.c
./doubly_linked_list
```

Then type commands: `i` followed by a string, `p`, `m`, `d`, `f`, and `q` to quit. Run it under
`valgrind` to confirm the free discipline — that is the check the project is really about.
