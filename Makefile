ALL:
	gcc *.c -Wall -ggdb -O0 -Wno-unused-result
clear:
	rm a.out
run:
	./a.out -a scc -i 0 -g 4 -f tests/input1.txt