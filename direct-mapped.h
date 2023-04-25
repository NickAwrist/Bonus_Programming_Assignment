#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "hexToBinary.h"
#include "binaryToDecimal.h"
#include "leak_detector_c.h"

struct Node;

int searchDM(struct Node *cache, char *trace, int index);
void directMapped(char *input);
