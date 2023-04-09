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
    bytesArray chunk;

    int chunkNum = 0;
    do {
        chunk = readBytes(pony_video, chunkNum * 16, 16);
        for (int i = 0; i < chunk.size; ++i) {
            printf("%d ", chunk.bytesPointer[i]);
        }
        free(chunk.bytesPointer);
        chunkNum++;
    } while (chunkNum < 3);

    fclose(pony_video);

    return 0;
}