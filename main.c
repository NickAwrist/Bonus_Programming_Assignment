#include <stdio.h>

#include "fully-associative.h"
#include "n-way.h"
#include "direct-mapped.h"

int main() {

    fullyAssociative("traces.txt");
    printf("\n");
    directMapped("traces.txt");
    printf("\n");
    nWay("traces.txt", 2);
    printf("\n");
    nWay("traces.txt", 4);
    return 0;
}
