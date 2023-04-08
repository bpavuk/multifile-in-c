#include "library.h"

#include <stdio.h>

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

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    if (size == -1) {
        perror("Error getting file size");
    }

    fclose(fp);

    return size;
}

int readNextByte(FILE *fp) {
    return fgetc(fp);
}