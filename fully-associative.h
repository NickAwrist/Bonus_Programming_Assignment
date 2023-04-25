#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "leak_detector_c.h"
#include "hexToBinary.h"

struct Node;

int searchFA(struct Node *cache, char *trace);
void fullyAssociative(char *input);