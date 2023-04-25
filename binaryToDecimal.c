#include "binaryToDecimal.h"

int binaryToDecimal(char *binary) {
    int decimal = 0;
    int i, j;

    j = strlen(binary) - 1;

    for (i = 0; binary[i] != '\0'; i++) {
        decimal += (binary[i] - '0') * pow(2, j);
        j--;
    }


    return abs(decimal%32);
}