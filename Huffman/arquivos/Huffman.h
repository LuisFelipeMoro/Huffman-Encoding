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

Tree* buildTree(char symbols[], int frequencies[], int size);



