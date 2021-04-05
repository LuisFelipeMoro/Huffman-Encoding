#include "File.h"
#define N 255

void getBytesFrequency(char* filename, char* characters, int charactersLength, int* frequency, int frequencyLength) {
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
            characters[charactersLength] = (char)i;
            frequency[frequencyLength] = bytes[i];
            charactersLength++;
            frequencyLength++;
        }
    }
}