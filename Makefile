all:
	gcc -o Testes/bin/Teste1 Testes/Teste1.c File.c Huffman.c Structures/Heap.c Structures/PriorityQueue.c Print.c 
	gcc -o Testes/bin/Teste2 Testes/Teste2.c File.c Huffman.c Structures/Heap.c Structures/PriorityQueue.c Print.c 
	gcc -o Testes/bin/Teste3 Testes/Teste3.c File.c Huffman.c Structures/Heap.c Structures/PriorityQueue.c Print.c 
	#	digite o comando "make test" para iniciar os testes

test:
	./Testes/bin/Teste1
	./Testes/bin/Teste2
	./Testes/bin/Teste3

clean:
	rm Testes/bin/*