#include "Huffman.h"

//Cria nós
struct HuffmanNode* newNode(char s, int freq){

	struct HuffmanNode* temp = (struct HuffmanNode*)malloc(sizeof(struct HuffmanNode));
		
	temp->left = temp->right = NULL;
	temp->symbol = s;
	temp->frequency = freq;

	return temp;
}
