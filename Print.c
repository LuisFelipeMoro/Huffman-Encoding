#include "Print.h"

//Imprime a representação da compressão na árvore como H code, imprimindo apenas as folhas 
//que são os caracteres do input
void printHCodes(Node* raiz, int arr[], int top){
	if (raiz->left) {
	arr[top] = 0;
	printHCodes(raiz->left, arr, top + 1);
  }
  if (raiz->right) {
	arr[top] = 1;
	printHCodes(raiz->right, arr, top + 1);
  }
  if (isLeaf(raiz)) {
	printCharacter(raiz->symbol);
	printVetor(arr, top);
  }
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
		printf("\\n  | ");
		return;
	}
	printf(" %c  | ", symbol);
}

//Checa se o Nó recebido é uma folha
int isLeaf(Node *node){
	return (node->left) == 0 && (node->right) == 0;
}