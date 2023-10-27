CC = gcc
FLAGS = -std=c99 -O0 -Wall -Werror -g -pedantic

default:
	$(CC) $(FLAGS) rgrep.c matcher.c -o rgrep

clean:
	rm -f rgrep
	rm -rf *.dSYM

check:
	test "`echo -e "a\nb\nc" | grep 'a'`" = "a"
	test "`echo -e "a\n" | grep 'a'`" = "a"
	test "`echo -e "a" | grep '...'`" = ""
	test "`echo -e "abc" | grep '.b.'`" = "abc"
	test "`echo -e "h\naaaaah" | grep -E 'a+h'`" = "aaaaah"
	test "`echo -e "h\naaaaahhhhh" | grep -E 'aa+hh+'`" = "aaaaahhhhh"
	test "`echo -e "h\naaaaahhhhh\n" | grep -E 'aa+hh+'`" = "aaaaahhhhh"
	test "`echo -e "woot\nwot\nwat\n" | grep -E 'wo?t'`" = "wot"
	test "`echo -e "CCCCCCC\nC+\nC++" | grep -E '.\+\+'`" = "C++"
	test "`echo -e "GG" | grep -E 'G+'`" = "GG"
	test "`echo -e "USF_CS221.jpg" | grep -E 'U.F_CL?S2+1\\.jpg'`" = "USF_CS221.jpg"
	test "`echo -e "a\nb" | grep 'a.b'`" = ""
	test "`echo -e "aaaa" | grep -E 'z+'`" = ""
	test "`echo -e "colo" | grep -E 'colo?r?'`" = "colo"
	test "`echo -e "data\\.txt" | grep 'data\\\.txt'`" = "data\.txt"
	@echo "Passed sanity check."
