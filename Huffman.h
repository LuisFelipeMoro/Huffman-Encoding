#include <stdio.h>
#include <stdlib.h>
#include "Structures/PriorityQueue.h"

struct No *buildHuffmanTree(char symbol[], int freq[], int size);

void printHCodes(struct HuffmanNode *raiz, int arr[], int top);