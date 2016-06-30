ALL:
	gcc *.c -Wall -ggdb -O0 -Wno-unused-result
clear:
	rm a.out
run:
	./a.out