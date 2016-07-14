ALL:
	gcc *.c -o graphs -O3 -Wno-unused-result
clear:
	rm graphs
run:
	./graphs -a scc -i 0 -g 4 -f tests/input.txt