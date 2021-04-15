#include <stdio.h>
#include <stdlib.h>
#include "Structures/PriorityQueue.h"
#include "Print.h"

Node *buildHuffmanTree(char symbol[], int freq[], int size); 

void useHuffman(char symbol[], int freq[], int size);