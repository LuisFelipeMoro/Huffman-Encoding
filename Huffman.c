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

	Node *root = extractMin(minHeap);
	minHeap = freeMinHeap(minHeap);
	return root;
}

void getHuffmanCodes(Node* raiz, char arr[], Node *map[], int top){
	if (raiz->left) {
		arr[top] = '0';
		getHuffmanCodes(raiz->left, arr, map, top + 1);
	}
	if (raiz->right) {
		arr[top] = '1';
		getHuffmanCodes(raiz->right, arr, map, top + 1);
	}
	if (isLeaf(raiz)) {
		map[raiz->symbol] = raiz;
		raiz->code = (char *)malloc((top + 1) * sizeof(char));
		strncpy(raiz->code, arr, top);
		raiz->code[top + 1] = 0;
	}
}

//Função que junta as chamadas das funções de contrução
//da árvore de huffman e a impressão dos H codes
void useHuffman(char* filename) {
	char characters[255];
	int frequency[255];
	int size = 0;

	getBytesFrequency(filename, (char*)&characters, (int*)&frequency, &size);

	Node *raiz = buildHuffmanTree(characters, frequency, size);

	Node *map[255];
	char arr[MAX_TREE_HEIGHT];

	for (int i = 0; i < 255; i++) {
		map[i] = NULL;
	}

	for (int i = 0; i < MAX_TREE_HEIGHT; i++) {
		arr[i] = 0;
	}

	getHuffmanCodes(raiz, arr, map, 0);

	printf(" Char\t| Frequency \t| Huffman code\n");
	printf("---------------------------------------\n");
	printHCodes(raiz);

	freeNode(raiz);
}