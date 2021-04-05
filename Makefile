all:
	gcc -o prog prog.c File.c && ./prog
clean:
	rm prog