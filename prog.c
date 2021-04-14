#include <stdio.h>
#include <string.h>
#include "File.h"
#include "Huffman.h"

int main() {

  char arr[] = {'A', 'B', 'C', 'D'};
  int freq[] = {5, 1, 6, 3};

  int size = 4;

  printf(" Char | Huffman code ");
  printf("\n--------------------\n");

  useHuffman(arr, freq, size);
	
}