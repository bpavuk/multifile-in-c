//
//  Edit this file as you wish. main.c is used as test polygon for library
//
#include "multifile.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("%ld\n", getFileSize("/home/pavuk/pony_fuckery.mp4"));
    FILE *pony_video = fopen("/home/pavuk/pony_fuckery.mp4", "rb");

    rewind(pony_video);
    bytesArray chunk = readBytes(pony_video, 0, 1024);

    int chunkNum = 1;
    int test1 = chunk.bytesPointer[chunk.size - 1];
    int test2;
    do {
        for (int i = 0; i < chunk.size; ++i) {
            printf("%d ", chunk.bytesPointer[i]);
        }
        free(chunk.bytesPointer);
        chunk = readBytes(pony_video, chunkNum * 1024, 1024);
        test2 = chunk.bytesPointer[0];
    } while (chunk.bytesPointer[chunk.size - 1] != -1);

    free(chunk.bytesPointer);

    return 0;
}