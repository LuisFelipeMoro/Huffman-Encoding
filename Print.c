#include "Print.h"

int printNode(int frequency, int totalBytes, int compressedBits, char code[]) {
	int bits = frequency * 8;
	double relativeFrequency = ((double)frequency)/totalBytes;
	double rate = (double)compressedBits/bits;
	printf("\t| %4d (%4.1f%%)\t| %4d\t|%5.1f%%\t| %11d\t| %s\n", frequency, relativeFrequency*100.0, bits, rate*100.0, compressedBits, code);
}

//Imprime a representação da compressão na árvore como H code, imprimindo apenas as folhas 
//que são os caracteres do input
int printHCodes(Node* raiz, int totalBytes){
	if (raiz == NULL) {
		return 0;
	}
	int left = printHCodes(raiz->left, totalBytes);
	int right = printHCodes(raiz->right, totalBytes);
	if (raiz->code != NULL) {
		printf(" ");
		printCharacter(raiz->symbol);
		int compressedBits = raiz->frequency * strlen(raiz->code);
		printNode(raiz->frequency, totalBytes, compressedBits, raiz->code);
		return compressedBits + left + right;
	}
	return left + right;
}

//Imprime um vetor recebido de tamanho N
void printVetor( int array[], int n){
	for(int i = 0; i < n; i++){
		printf("%d", array[i]);
	}
	printf("\n");	
}

void printCharacter(char symbol){
	if(symbol == '\n'){
		printf("\\n");
		return;
	}
	printf("%c", symbol);
}

//Checa se o Nó recebido é uma folha
int isLeaf(Node *node){
	return (node->left) == 0 && (node->right) == 0;
}