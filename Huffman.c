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