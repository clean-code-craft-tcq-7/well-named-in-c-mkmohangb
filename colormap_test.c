#include <stdio.h>
#include <assert.h>
#include "color_conversion.h"
#include "ref_manual_formatter.h"
#include <string.h>

void testNumberToPair(int pairNumber,
    enum MajorColor expectedMajor,
    enum MinorColor expectedMinor)
{
    ColorPair colorPair = GetColorFromPairNumber(pairNumber);
    char colorPairNames[MAX_COLORPAIR_NAME_CHARS];
    ColorPairToString(&colorPair, colorPairNames);
    printf("Got pair %s\n", colorPairNames);
    assert(colorPair.majorColor == expectedMajor);
    assert(colorPair.minorColor == expectedMinor);
}

void testPairToNumber(
    enum MajorColor major,
    enum MinorColor minor,
    int expectedPairNumber)
{
    ColorPair colorPair;
    colorPair.majorColor = major;
    colorPair.minorColor = minor;
    int pairNumber = GetPairNumberFromColor(&colorPair);
    printf("Got pair number %d\n", pairNumber);
    assert(pairNumber == expectedPairNumber);
}

void testPrintReferenceManual() {
    char buf[100];
    md_header(buf, 100);
    assert(strcmp(buf, "|Pair Number|Major Color|Minor Color|\n|---|---|---|\n") == 0);

    md_format_row(buf, 100, 1, WHITE, BLUE);
    assert(strcmp(buf, "|1|White|Blue|\n") == 0);
    printReferenceManual(md_header, md_format_row);
}

void testPrintReferenceManualCsv(){
    char buf[100];
    csv_header(buf, 100);
    assert(strcmp(buf, "Pair Number,Major Color,Minor Color\n") == 0);

    csv_format_row(buf, 100, 1, WHITE, BLUE);
    assert(strcmp(buf, "1,White,Blue\n") == 0);
    printReferenceManual(csv_header, csv_format_row);
}

int main() {
    testNumberToPair(4, WHITE, BROWN);
    testNumberToPair(5, WHITE, SLATE);

    testPairToNumber(BLACK, ORANGE, 12);
    testPairToNumber(VIOLET, SLATE, 25);

    printf("calling print reference manual\n");
    testPrintReferenceManual();

    return 0;
}
