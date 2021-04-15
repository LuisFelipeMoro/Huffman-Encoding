#include "File.h"
#define N 255

void getBytesFrequency(char* filename, char* characters, int* frequency, int* frequencyLength) {
	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		printf("Failed to read file: %s", filename);
		return;
	}
	int bytes[N];
	int byte;
	for (int i = 0; i < N; i++) {
		bytes[i] = 0;
	}
	do {
		byte = fgetc(file);
		if (byte != EOF) {
			bytes[byte]++;
		}
	} while (byte != EOF);
	fclose(file);
	for (int i = 0; i < N; i++) {
		if (bytes[i] > 0) {
			characters[*frequencyLength] = (char)i;
			frequency[*frequencyLength] = bytes[i];
			(*frequencyLength)++;
		}
	}
}

int testFile() {
	char characters[N];
	int frequency[N];
	int frequencyLength = 0;
	printf("\nFile: Exemplos/alfabeto.txt\n");
	getBytesFrequency("Exemplos/alfabeto.txt", (char*)&characters, (int*)&frequency, &frequencyLength);
	for (int i = 0; i < frequencyLength; i++) {
		int ok = i == 0 && characters[i] == '\n' && frequency[i] == 26;
		ok = ok || frequency[i] == (27 - i);
		printf("Character: %c Frequency: %d %s\n", characters[i], frequency[i], ok ? "PASS" : "FAIL");
		if (!ok) { return 0; }
	}
	frequencyLength = 0;
	printf("\nFile: Exemplos/alfabetoInverso.txt\n");
	getBytesFrequency("Exemplos/alfabetoInverso.txt", (char*)&characters, (int*)&frequency, &frequencyLength);
	for (int i = 0; i < frequencyLength; i++) {
		int ok = i == 0 && characters[i] == '\n' && frequency[i] == 26;
		ok = ok || frequency[i] == i;
		printf("Character: %c Frequency: %d %s\n", characters[i], frequency[i], ok ? "PASS" : "FAIL");
		if (!ok) { return 0; }
	}
	return 1;
}