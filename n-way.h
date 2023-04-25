#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "leak_detector_c.h"
#include "hexToBinary.h"
#include "binaryToDecimal.h"

struct Node;

struct Set;

int searchnWay(struct Set *cache, char* trace, int n, int set);

void nWay(char *input, int n);