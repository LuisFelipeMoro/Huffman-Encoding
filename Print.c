#include "Print.h"

//Imprime a representação da compressão na árvore como H code, imprimindo apenas as folhas 
//que são os caracteres do input
void printHCodes(Node* raiz){
	if (raiz == NULL) {
		return;
	}
	printHCodes(raiz->left);
	printHCodes(raiz->right);
	if (raiz->code != NULL) {
		printf(" ");
		printCharacter(raiz->symbol);
		printf("\t| %02d\t\t| %s\n", raiz->frequency, raiz->code);
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
		printf("\\n");
		return;
	}
	printf("%c", symbol);
}

//Checa se o Nó recebido é uma folha
int isLeaf(Node *node){
	return (node->left) == 0 && (node->right) == 0;
}