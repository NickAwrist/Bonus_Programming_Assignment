#include "hexToBinary.h"

char* hexToBinary(char* hex){

    char *binary = malloc(sizeof(char)*100);
    int currentIndex = 0;

    int i = 0;
    while (hex[i]) {

        switch (hex[i]) {
            case '0':
                binary[currentIndex] = '0';
                binary[currentIndex+1] = '0';
                binary[currentIndex+2] = '0';
                binary[currentIndex+3] = '0';
                break;
            case '1':
                binary[currentIndex] = '0';
                binary[currentIndex+1] = '0';
                binary[currentIndex+2] = '0';
                binary[currentIndex+3] = '1';
                break;
            case '2':
                binary[currentIndex] = '0';
                binary[currentIndex+1] = '0';
                binary[currentIndex+2] = '1';
                binary[currentIndex+3] = '0';
                break;
            case '3':
                binary[currentIndex] = '0';
                binary[currentIndex+1] = '0';
                binary[currentIndex+2] = '1';
                binary[currentIndex+3] = '1';
                break;
            case '4':
                binary[currentIndex] = '0';
                binary[currentIndex+1] = '1';
                binary[currentIndex+2] = '0';
                binary[currentIndex+3] = '0';
                break;
            case '5':
                binary[currentIndex] = '0';
                binary[currentIndex+1] = '1';
                binary[currentIndex+2] = '0';
                binary[currentIndex+3] = '1';
                break;
            case '6':
                binary[currentIndex] = '0';
                binary[currentIndex+1] = '1';
                binary[currentIndex+2] = '1';
                binary[currentIndex+3] = '0';
                break;
            case '7':
                binary[currentIndex] = '0';
                binary[currentIndex+1] = '1';
                binary[currentIndex+2] = '1';
                binary[currentIndex+3] = '1';
                break;
            case '8':
                binary[currentIndex] = '1';
                binary[currentIndex+1] = '0';
                binary[currentIndex+2] = '0';
                binary[currentIndex+3] = '0';
                break;
            case '9':
                binary[currentIndex] = '1';
                binary[currentIndex+1] = '0';
                binary[currentIndex+2] = '0';
                binary[currentIndex+3] = '1';
                break;
            case 'A':
            case 'a':
                binary[currentIndex] = '1';
                binary[currentIndex+1] = '0';
                binary[currentIndex+2] = '1';
                binary[currentIndex+3] = '0';
                break;
            case 'B':
            case 'b':
                binary[currentIndex] = '1';
                binary[currentIndex+1] = '0';
                binary[currentIndex+2] = '1';
                binary[currentIndex+3] = '1';
                break;
            case 'C':
            case 'c':
                binary[currentIndex] = '1';
                binary[currentIndex+1] = '1';
                binary[currentIndex+2] = '0';
                binary[currentIndex+3] = '0';
                break;
            case 'D':
            case 'd':
                binary[currentIndex] = '1';
                binary[currentIndex+1] = '1';
                binary[currentIndex+2] = '0';
                binary[currentIndex+3] = '1';
                break;
            case 'E':
            case 'e':
                binary[currentIndex] = '1';
                binary[currentIndex+1] = '1';
                binary[currentIndex+2] = '1';
                binary[currentIndex+3] = '0';
                break;
            case 'F':
            case 'f':
                binary[currentIndex] = '1';
                binary[currentIndex+1] = '1';
                binary[currentIndex+2] = '1';
                binary[currentIndex+3] = '1';
                break;
        }
        currentIndex += 4;
        i++;
    }

    return binary;
}