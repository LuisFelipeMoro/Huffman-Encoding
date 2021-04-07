#include <stdio.h>
#include <stdlib.h>
#include "Structures/PriorityQueue.h"

struct Heap *createAndBuildMinHeap(char symbol[], int freq[], int size);

struct No *buildHuffmanTree(char symbol[], int freq[], int size);

void printHCodes(struct HuffmanNode *raiz, int arr[], int top);