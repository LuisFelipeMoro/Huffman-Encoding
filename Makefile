all:
	gcc -o prog prog.c File.c Huffman.c Structures/Heap.c Structures/PriorityQueue.c Print.c 
	./prog
clean:
	rm prog