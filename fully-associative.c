#include "fully-associative.h"

typedef struct Node{
    char *value;
}Node;

int searchFA(Node *cache, char *trace){
    for(int i=0; i<32; i++){

        if(cache[i].value == NULL || cache[i].value[0] == '\0')
            return 0;

        if(strcmp(cache[i].value, trace) == 0)
            return 1;
    }
    return 0;
}

void fullyAssociative(char *input){

    atexit(report_mem_leak);
    FILE *inputFile = NULL;
    inputFile = fopen(input, "r");

    Node *cache = malloc(sizeof(Node)*32);
    for(int i=0; i<32; i++)
        cache[i].value = NULL;

    int hits = 0;
    int misses = 0;
    int currentCacheIndex = 0;
    int totalLength = 0;

    while (totalLength != 9999){
        char *currentTrace = malloc(sizeof(char)*50);
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

        if(searchFA(cache, currentNode->value) == 1) {
            hits++;
        }
        else {
            misses++;
            cache[currentCacheIndex] = *currentNode;
            currentCacheIndex = currentCacheIndex%32;
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
    printf("Fully associative:\nHit rate = %.2lf %\nMiss rate = %.2lf %\n", hitRate, missRate);
}
