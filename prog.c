#include <stdio.h>
#include <string.h>
#include "File.h"
#include "Huffman.h"

int main() {

	char characters[255];
	int frequency[255];
	int frequencyLength = 0;

	getBytesFrequency("Exemplos/alfabeto.txt", (char*)&characters, (int*)&frequency, &frequencyLength);

	useHuffman(characters, frequency, frequencyLength);
	
}