# Your program must compile with 'make'
# You must not change this file.

CC = gcc
FLAGS = -std=c99 -O0 -Wall -Werror -g -pedantic

default:
	$(CC) $(FLAGS) rgrep.c matcher.c -o rgrep

clean:
	rm -f rgrep
	rm -rf *.dSYM

check: clean default
	# Simple literal matching
	test "`echo -e "a" | ./rgrep 'a'`" = "a"
	test "`echo -e "ba" | ./rgrep 'a'`" = "ba"
	test "`echo -e "ab" | ./rgrep 'a'`" = "ab"
	test "`echo -e "abc" | ./rgrep 'b'`" = "abc"
	test "`echo -e "b" | ./rgrep 'a'`" = ""
	test "`echo -e "abc" | ./rgrep ''`" = "abc"
	test "`echo -e "" | ./rgrep 'a'`" = ""
	test "`echo -e "a\n" | ./rgrep 'a'`" = "a"
	test "`echo -e "\na" | ./rgrep 'a'`" = "a"
	test "`echo -e "\na\n" | ./rgrep 'a'`" = "a"
	test "`echo -e "a\nb" | ./rgrep 'a'`" = "a"
	test "`echo -e "a\nb" | ./rgrep 'b'`" = "b"
	test "`echo -e "b\na\nc" | ./rgrep 'a'`" = "a"
	# Wildcard character matching
	test "`echo -e "a" | ./rgrep '.'`" = "a"
	test "`echo -e "ab" | ./rgrep '..'`" = "ab"
	test "`echo -e "abc" | ./rgrep '..'`" = "abc"
	test "`echo -e "g\nab" | ./rgrep '..'`" = "ab"
	test "`echo -e "ga\nabc\nhj" | ./rgrep '...'`" = "abc"
	test "`echo -e "a.b" | ./rgrep 'a.b'`" = "a.b"
	test "`echo -e "abc" | ./rgrep '.b.'`" = "abc"
	test "`echo -e "ga\nabcd" | ./rgrep '.a'`" = "ga"
	test "`echo -e "a\nbcd" | ./rgrep '..d'`" = "bcd"
	test "`echo -e "a" | ./rgrep '...'`" = ""
	test "`echo -e "a\nb" | ./rgrep 'a.b'`" = ""
	# Plus matching
	test "`echo -e "a" | ./rgrep 'a+'`" = "a"
	test "`echo -e "GG" | ./rgrep 'G+'`" = "GG"
	test "`echo -e "h\naaaaah" | ./rgrep 'a+h'`" = "aaaaah"
	test "`echo -e "h\naaaaahhhhh" | ./rgrep 'aa+hh+'`" = "aaaaahhhhh"
	test "`echo -e "h\naaaaahhhhh\n" | ./rgrep 'aa+hh+'`" = "aaaaahhhhh"
	test "`echo -e "aaaa" | ./rgrep 'z+'`" = ""
	# Question mark matching
	test "`echo -e "a" | ./rgrep 'a?'`" = "a"
	test "`echo -e "" | ./rgrep 'a?'`" = ""
	test "`echo -e "woot\nwot\nwat\n" | ./rgrep 'wo?t'`" = "wot"
	test "`echo -e "colo" | ./rgrep 'colo?r?'`" = "colo"
	# Escaping special characters
	test "`echo -e "." | ./rgrep '\.'`" = "."
	test "`echo -e "a" | ./rgrep '\.'`" = ""
	test "`echo -e "+" | ./rgrep '\+'`" = "+"
	test "`echo -e "?" | ./rgrep '\?'`" = "?"
	test "`echo "\a" | ./rgrep '\\a'`" = "\a"
	test "`echo -e "\\\\" | ./rgrep '\\\\'`" = "\\"
	test "`echo "data\.txt" | ./rgrep 'data\\\.txt'`" = "data\.txt"
	test "`echo -e "a+a?" | ./rgrep 'a\+a\?'`" = "a+a?"
	# Combining symbols
	test "`echo -e "CCCCCCC\nC+\nC++" | ./rgrep '.\+\+'`" = "C++"
	test "`echo -e "USF_CS221.jpg" | ./rgrep 'U.F_CL?S2+1\.jpg'`" = "USF_CS221.jpg"
	#test "`echo -e "h\n\\\\\\\h" | ./rgrep '\\+h'`" = "\\\h"
	test "`echo -e "a" | ./rgrep '\??'`" = "a"
	test "`echo -e "a?" | ./rgrep '\??'`" = "a?"
	#test "`echo -e "\\\\\\\\\\\\" | ./rgrep '\\+'`" = "\\\\\\"
	test "`echo -e "..." | ./rgrep '\.+'`" = "..."
	test "`echo -e "???" | ./rgrep '\?+'`" = "???"
	test "`echo -e "+++" | ./rgrep '\++'`" = "+++"
	@echo "Passed sanity check."

