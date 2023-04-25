#include "n-way.h"

typedef struct Node{
    char *value;
}Node;

typedef struct Set{
    Node *nodes;
}Set;

int searchnWay(Set *cache, char* trace, int n, int set){

    for(int i=0; i<n; i++){

        if(cache[set].nodes[i].value == NULL || cache[set].nodes[i].value[0] == '\0')
            return 0;

        if(strcmp(cache[set].nodes[i].value, trace) == 0)
            return 1;
    }
    return 0;

}

void nWay(char *input, int n){
    atexit(report_mem_leak);
    FILE *inputFile = NULL;
    inputFile = fopen(input, "r");

    int sets = 32/n;
    Set *cache = malloc(sizeof(Set)*sets);
    for(int i=0; i<sets; i+=n){
        cache[i].nodes = malloc(sizeof(Node)*n);
        for(int j=0; j<n; j++){
            cache[i].nodes[j].value = NULL;
        }
    }

    int hits = 0;
    int misses = 0;
    int totalLength = 0;

    while (totalLength!=9999){

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

        int set = binaryToDecimal(currentNode->value)%sets;
        if(searchnWay(cache, currentNode->value, n, set)){
            hits++;
        }else{
            misses++;
            cache[set].nodes[totalLength%n] = *currentNode;
        }
        totalLength++;

        free(currentNode->value);
        free(currentNode);
        free(trace);
        free(currentTrace);
    }

    int result = fclose(inputFile);
    if(result != 0){
        printf("Error closing input file: %s\n", input);
    }

    double hitRate = (((double) hits)/totalLength)*100;
    double missRate = (((double) misses)/totalLength)*100;

    free(cache);

    printf("%d-Way Mapped:\nHit rate = %.2lf %\nMiss rate = %.2lf %\n", n, hitRate, missRate);

}