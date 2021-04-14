#include <stdio.h>
#include <string.h>
#include "File.h"
#include "Huffman.h"

int main() {

  char characters[255];
	int frequency[255];
	int frequencyLength = 0;
	printf("\nFile: Exemplos/alfabeto.txt\n");
	getBytesFrequency("Exemplos/alfabeto.txt", (char*)&characters, (int*)&frequency, &frequencyLength);
	for (int i = 0; i < frequencyLength; i++) {
		int ok = i == 0 && characters[i] == '\n' && frequency[i] == 26;
		ok = ok || frequency[i] == (27 - i);
		printf("Character: %c Frequency: %d %s\n", characters[i], frequency[i], ok ? "PASS" : "FAIL");
		if (!ok) { return 0; }
	}

  useHuffman(characters, frequency, frequencyLength);
	
}