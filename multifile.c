#include "multifile.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @param filename - name of file
 * @return file size in bytes, -1 if error happened
 */
long getFileSize(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    long size = getFileSizeByPointer(fp);

    fclose(fp);

    return size;
}

long getFileSizeByPointer(FILE *fp) {
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    if (size == -1) {
        perror("Error getting file size");
    }
    rewind(fp);
    return size;
}

int readNextByte(FILE *fp) {
    return fgetc(fp);
}

bytesArray readBytes(FILE *fp, long startFrom, long howMuch) {
    long arraySize = howMuch < getFileSizeByPointer(fp) + 1 ? howMuch : getFileSizeByPointer(fp);
    int* array = (int*)malloc(arraySize * sizeof(int));

    fseek(fp, startFrom + howMuch, SEEK_SET);

    for (int i = 0; i < arraySize; i++) {
        array[i] = readNextByte(fp);
    }

    bytesArray Array = {.size = arraySize, .bytesPointer = array};
    return Array;
}