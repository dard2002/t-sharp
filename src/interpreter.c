#include "interpreter.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"
#include "token.h"

int num_of_integers = 0;
int integers_size = 5;
Integer** integers = NULL;

void garbage_collection() {
    for (int i = 0; i < num_of_integers; ++i) {
        free_int(integers[i]);
    }

    free(integers);
}

int run(Node* nodes, int num_of_tokens) {
    // Dummy example - declare a variable
    for (int i = 0; i < num_of_tokens; ++i) {
        if (nodes[i].token.type == TK_KEYWORD) {
            if (strcmp(nodes[i].token.value, keywords[1]) == 0) {
                if (nodes[i + 1].token.type == TK_VARIABLE_NAME) {
                    if (nodes[i + 2].token.type == TK_OPERATOR) {
                        if (nodes[i + 3].token.type == TK_VARIABLE_VALUE && nodes[i + 4].token.type == TK_LINE_END) {
                            if (integers == NULL) {
                                integers = malloc(integers_size * sizeof(Integer*));
                            }
                            if (num_of_integers == integers_size) {
                                integers_size += 5;
                                integers = realloc(integers, integers_size * sizeof(Integer*));
                            }

                            integers[num_of_integers] = create_int(nodes[1].token.value, (int)strtol(nodes[3].token.value, (char**)NULL, 10));
                            // Debugging purposes
                            printf("Integer %s has value %d\n", integers[num_of_integers]->name, integers[num_of_integers]->value);
                            num_of_integers++;
                        }
                    }
                }
            }
        }
    }

    garbage_collection();
    return 0;
}