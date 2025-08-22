#include <stdio.h>
#include "color_conversion.h"

void md_header(char* buffer, int size) {
    snprintf(buffer, size, "|Pair Number|Major Color|Minor Color|\n|---|---|---|\n");
}

void printReferenceManual() {
    printf("Color Code Manual\n");
    for (int i =0; i< 25; i++) {
        ColorPair colorPair = GetColorFromPairNumber(i + 1);
        char colorPairNames[MAX_COLORPAIR_NAME_CHARS];
        ColorPairToString(&colorPair, colorPairNames);
        printf("%2d | %s\n", i + 1, colorPairNames);
    }
}