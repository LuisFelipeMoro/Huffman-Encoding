#include <stdio.h>
#include <string.h>
#include "Structures/Node.h"

int printNode(int frequency, int totalBytes, int compressedBits, char code[]);

int printHCodes(Node* raiz, int totalBytes); 

void printVetor(int array[], int n); 

void printCharacter(char symbol);

int isLeaf(Node *node); 