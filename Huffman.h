#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Structures/PriorityQueue.h"
#include "Print.h"

Node *buildHuffmanTree(char symbol[], int freq[], int size); 

void getHuffmanCodes(Node* raiz, char arr[], Node *map[], int top);

void useHuffman(char symbol[], int freq[], int size);