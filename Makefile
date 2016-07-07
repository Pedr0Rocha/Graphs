ALL:
	gcc *.c -Wall -ggdb -O0 -Wno-unused-result
clear:
	rm a.out
run:
	./a.out -a dfs -i 0 -f tests/input1.txt