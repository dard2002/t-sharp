#include <stdio.h>
#include <stdlib.h>
#include "int.h"

Integer* create_int(char* name, int value) {
    Integer* i = malloc(sizeof(Integer));
    i->name = name;
    i->value = value;

    return i;
}

void free_int(Integer* i) {
    free(i);
    i = NULL;
}
