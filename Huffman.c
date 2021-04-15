#include "Huffman.h"

#define MAX_TREE_HEIGHT 50


// Constroe a árvore de huffman utilizando do minHeap para criar uma fila de prioridade, assim retirando
//as duas menores ocorrências e montando a árvore a partir de suas folhas.
Node *buildHuffmanTree(char symbol[], int frequency[], int size) {
	Node *left, *right, *top;
	Heap *minHeap = createAndBuildMinHeap(symbol, frequency, size);

	while (!checkSizeOne(minHeap)) {
		left = extractMin(minHeap);
		right = extractMin(minHeap);

		top = newNode('$', left->frequency + right->frequency);

		top->left = left;
		top->right = right;

		insertMinHeap(minHeap, top);
	}
	return extractMin(minHeap);
}

//Função que junta as chamadas das funções de contrução
//da árvore de huffman e a impressão dos H codes
void useHuffman(char symbol[], int freq[], int size) {

	Node *raiz = buildHuffmanTree(symbol, freq, size);

	int arr[MAX_TREE_HEIGHT], top = 0;

	printf(" Char | Huffman code ");
	printf("\n--------------------\n");
	printHCodes(raiz, arr, top);

}