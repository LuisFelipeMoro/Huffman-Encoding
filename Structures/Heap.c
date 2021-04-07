#include "Heap.h"

//Cria um  Nó de Huffman e o inicializa.
struct HuffmanNode* newNode(char s, int freq){

	struct HuffmanNode* temp = (struct HuffmanNode*)malloc(sizeof(struct HuffmanNode));
		
	temp->left = temp->right = NULL;
	temp->symbol = s;
	temp->frequency = freq;

	return temp;
}

//Checa se o tamanho da fila/heap é 1, ou seja se chegamos ao fiz
//da inserção
//Retorna 1 caso o tamanho seja 1 e 0 caso não seja.
int checkSizeOne(struct Heap *minHeap){
		return (minHeap->size == 1);
}

//Troca o apontamento de dois Nós.
void swapNode( struct HuffmanNode **a, struct HuffmanNode **b){
	struct HuffmanNode *temp = *a;
	*a = *b;
	*b = temp;
}

//Checa se o Nó recebido é uma folha
int isLeaf(struct HuffmanNode *node){
	return !(node->left) && !(node->right);
}


//Imprime um vetor recebido de tamanho N
void printVetor( int array[], int n){
	for(int i = 0; i < n; i++){
		printf("%d", array[i]);
	}
	printf("\n");	
}