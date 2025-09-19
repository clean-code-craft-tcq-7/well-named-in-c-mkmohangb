#include <stdio.h>
#include "color_conversion.h"

void md_header(char* buffer, int size) {
    snprintf(buffer, size, "|Pair Number|Major Color|Minor Color|\n|---|---|---|\n");
}

void md_format_row(char* buffer, int size, int pairNumber, enum MajorColor major, enum MinorColor minor) {
    snprintf(buffer, size, "|%d|%s|%s|\n", pairNumber,
             MajorColorNames[major], MinorColorNames[minor]);
}

void csv_header(char* buffer, int size) {
    snprintf(buffer, size, "Pair Number,Major Color,Minor Color\n");
}

void csv_format_row(char* buffer, int size, int pairNumber, enum MajorColor major, enum MinorColor minor) {
    snprintf(buffer, size, "%d,%s,%s\n", pairNumber,
             MajorColorNames[major], MinorColorNames[minor]);
}

void printReferenceManual(void (*header_formatter)(), void (*row_formatter)()) {
    printf("Color Code Manual\n");
    char buf[100];
    //md_header(buf, 100);
    header_formatter(buf, 100);
    printf("%s", buf);
    for (int i =0; i< 25; i++) {
        ColorPair colorPair = GetColorFromPairNumber(i + 1);
        char colorPairNames[MAX_COLORPAIR_NAME_CHARS];
        ColorPairToString(&colorPair, colorPairNames);
        //md_format_row(buf, 100, i + 1, colorPair.majorColor, colorPair.minorColor);
        row_formatter(buf, 100, i + 1, colorPair.majorColor, colorPair.minorColor);
        printf("%s", buf);
    }
}