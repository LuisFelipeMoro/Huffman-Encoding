#include "Huffman.h"

//Imprime a representação da compressão como H code
void printHCodes(struct HuffmanNode* raiz, int arr[], int top){
	if (raiz->left) {
	arr[top] = 0;
	printHCodes(raiz->left, arr, top + 1);
  }
  if (raiz->right) {
	arr[top] = 1;
	printHCodes(raiz->right, arr, top + 1);
  }
  if (isLeaf(raiz)) {
	printf("  %c   | ", raiz->symbol);
	printVetor(arr, top);
  }
}

// Constroe a árvore de huffman utilizando do minHeap para criar uma fila de prioridade, assim retirando
//as menores ocorrências e montando a árvore a partir de suas folhas.
struct HuffmanNode *buildHuffmanTree(char symbol[], int frequency[], int size) {
  struct HuffmanNode *left, *right, *top;
  struct Heap *minHeap = createAndBuildMinHeap(symbol, frequency, size);

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