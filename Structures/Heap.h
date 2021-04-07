#include <stdio.h>
#include <stdlib.h>

typedef struct HuffmanNode{
	char symbol;
	int frequency;
	struct HuffmanNode* left;
	struct HuffmanNode* right;
}No, Tree;

typedef struct Heap {
	unsigned size;
	unsigned capacity;
	struct HuffmanNode** array;
};

struct HuffmanNode* newNode(char s, int freq);

struct Heap *newMinHeap(unsigned capacity);

void swapNode(struct HuffmanNode **a, struct HuffmanNode **b);

void minHeapify(struct Heap *minHeap, int idx);

int checkSizeOne(struct Heap *minHeap);

int isLeaf(struct HuffmanNode *node);

void printVetor(int array[], int n);
