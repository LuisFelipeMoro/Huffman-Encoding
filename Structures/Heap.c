#include "Heap.h"

//Cria um  Nó de Huffman e o inicializa.
struct HuffmanNode* newNode(char s, int freq){

	struct HuffmanNode* temp = (struct HuffmanNode*)malloc(sizeof(struct HuffmanNode));
		
	temp->left = temp->right = NULL;
	temp->symbol = s;
	temp->frequency = freq;

	return temp;
}

//Cria um MinHeap e o Inicializa.
struct Heap *newMinHeap(unsigned capacity){
	struct Heap *minHeap = (struct Heap *)malloc(sizeof(struct Heap));

	minHeap->size = 0;

	minHeap->capacity = capacity;

	minHeap->array = (struct HuffmanNode **)malloc(minHeap->capacity * sizeof(struct HuffmanNode *));

	return minHeap;
}

//Checa se o tamanho da fila/heap é 1, ou seja se chegamos ao fiz
//da inserção na árvore.
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
	return (node->left) == 0 && (node->right) == 0;
}


//Imprime um vetor recebido de tamanho N
void printVetor( int array[], int n){
	for(int i = 0; i < n; i++){
		printf("%d", array[i]);
	}
	printf("\n");	
}

//Realiza o heapify no vetor de Nós para transformalo em um MinHeap
void minHeapify(struct Heap *minHeap, int i){
	int smallest = i;
	int left = (2 * i) + 1;
	int right = (2 * i) + 2;

  if (left < minHeap->size && minHeap->array[left]->frequency < minHeap->array[smallest]->frequency)
	smallest = left;

  if (right < minHeap->size && minHeap->array[right]->frequency < minHeap->array[smallest]->frequency)
	smallest = right;

  if (smallest != i) {
	swapNode(&minHeap->array[smallest], &minHeap->array[i]);
	minHeapify(minHeap, smallest);
  }
}

//Constroe o minHeap utilizando-se dos membros do vetor que tem filhos, começando
//do ultimo nó a ter filhos dentro do vetor
void buildMinHeap(struct Heap *minHeap){

	int n = minHeap->size - 1;

  for (int i = (n - 1)/2; i >= 0; --i)
    minHeapify(minHeap, i);
}

//Cria o minHeap, insere os nós dentro de seu vetor e chama o método buildMinHeap
struct Heap *createAndBuildMinHeap(char symbol[], int frequency[], int size) {

  struct Heap *minHeap = newMinHeap(size);

  for (int i = 0; i < size; ++i)
    minHeap->array[i] = newNode(symbol[i], frequency[i]);

  minHeap->size = size;
  buildMinHeap(minHeap);

  return minHeap;
}