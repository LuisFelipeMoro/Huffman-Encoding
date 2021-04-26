all:
	gcc -o Testes/bin/Teste1 Testes/Teste1.c File.c  
	gcc -o Testes/bin/Teste2 Testes/Teste2.c File.c Huffman.c Structures/Heap.c Structures/PriorityQueue.c Print.c 
	gcc -o Testes/bin/Teste3 Testes/Teste3.c File.c Huffman.c Structures/Heap.c Structures/PriorityQueue.c Print.c 
	gcc -o Testes/bin/Teste4 Testes/Teste4.c File.c Huffman.c Structures/Heap.c Structures/PriorityQueue.c Print.c 
	gcc -o Testes/bin/Teste5 Testes/Teste5.c File.c Huffman.c Structures/Heap.c Structures/PriorityQueue.c Print.c 

	./Testes/bin/Teste1
	./Testes/bin/Teste2
	./Testes/bin/Teste3
	./Testes/bin/Teste4
	./Testes/bin/Teste5

clean:
	rm Testes/*