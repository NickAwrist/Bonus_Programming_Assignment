#include "direct-mapped.h"

typedef struct Node{
    char *value;
}Node;

int searchDM(Node *cache, char *trace, int index){

    if(cache[index].value == NULL || cache[index].value[0] == '\0')
        return 0;

    return !strcmp(cache[index].value, trace);
}

void directMapped(char *input){

    atexit(report_mem_leak);
    FILE *inputFile = NULL;
    inputFile = fopen(input, "r");

    Node *cache = malloc(sizeof(Node)*32);
    for(int i=0; i<32; i++)
        cache[i].value = NULL;

    int hits = 0;
    int misses = 0;
    int totalLength = 0;

    while (totalLength!=9999){
        char *currentTrace = malloc(sizeof(char)*100);
        if(fscanf(inputFile, "%s", currentTrace) != 1){
            free(currentTrace);
            break;
        }

        int length = (int) strlen(currentTrace);
        char *trace = (char*) calloc(length + 1, sizeof(char));

        for(int i=2; i<length; i++){
            strcpy(&trace[i-2], &currentTrace[i]);
        }

        Node *currentNode = malloc(sizeof(Node));
        currentNode->value = malloc(sizeof(char)*100);

        strcpy(currentNode->value, hexToBinary(trace));

        int index = binaryToDecimal(currentNode->value);
        if(searchDM(cache, currentNode->value, index)){
            hits++;
        }else{
            misses++;
            cache[index] = *currentNode;
        }
        totalLength++;

        free(currentNode->value);
        free(currentNode);
        free(trace);
        free(currentTrace);
    }

    fclose(inputFile);
    double hitRate = (((double) hits)/totalLength)*100;
    double missRate = (((double) misses)/totalLength)*100;

    free(cache);
    printf("Direct-Mapped:\nHit rate = %.2lf %\nMiss rate = %.2lf %\n", hitRate, missRate);

}

