#ifndef MULTIFILE_IN_C_LIBRARY_H
#define MULTIFILE_IN_C_LIBRARY_H

#include <stdio.h>

extern long getFileSize(const char *filename);
extern int readNextByte(FILE *fp);

#endif //MULTIFILE_IN_C_LIBRARY_H
