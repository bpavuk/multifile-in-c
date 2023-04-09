#include "multifile.h"

#include <stdio.h>
#include <malloc.h>

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

bytesArray readBytes(FILE *fp, long startFrom, long howMuch) {
    long fileSize = getFileSizeByPointer(fp);
    long arraySize = startFrom + howMuch <= fileSize ? howMuch : fileSize - startFrom;
    char* buffer = (char*)malloc(arraySize * sizeof(char));
    bytesArray Array = {.bytesPointer = buffer, .size = -1};
    if (buffer == NULL){
        errno = ENOMEM;
        perror("Error allocating memory");
    } else {
        fseek(fp, startFrom, SEEK_SET);
        if (fread(buffer, sizeof(char), howMuch, fp) == howMuch) {
            Array.size = arraySize;
        }
    }
    return Array;
}

void freeBytesArray(bytesArray* array) {
    if (array == NULL) {
        errno = EINVAL; // Invalid argument error
        perror("Error freeing memory");
    }
    free(array->bytesPointer);
    free(array);
}