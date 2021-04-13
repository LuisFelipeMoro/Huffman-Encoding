#include <stdio.h>
#include <stdlib.h>
#include "Structures/PriorityQueue.h"

struct HuffmanNode *buildHuffmanTree(char symbol[], int freq[], int size); 

void printHCodes(struct HuffmanNode *raiz, int arr[], int top); 

void Huffman(char symbol[], int freq[], int size);