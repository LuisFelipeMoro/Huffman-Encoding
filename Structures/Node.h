#ifndef NODE
#define NODE

typedef struct HuffmanNode{
	char symbol;
	int frequency;
	struct HuffmanNode* left;
	struct HuffmanNode* right;
}Node, Tree;

#endif