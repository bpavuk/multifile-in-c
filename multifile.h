#ifndef MULTIFILE_IN_C_MULTIFILE_H
#define MULTIFILE_IN_C_MULTIFILE_H

#include <stdio.h>

typedef struct {
    long size;
    char* bytesPointer;
} bytesArray;

extern long getFileSize(const char *filename);
extern bytesArray readBytes(FILE *fp, long startFrom, long howMuch);
extern long getFileSizeByPointer(FILE *fp);

#endif //MULTIFILE_IN_C_MULTIFILE_H
