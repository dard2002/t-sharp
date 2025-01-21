#include "node.h"

#include <stdio.h>
#include <stdlib.h>

Node* create_nodes(Token* tokens, int num_of_tokens) {
    Node* nodes = malloc(num_of_tokens * sizeof(Node));
    if (!nodes) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < num_of_tokens; ++i) {
        nodes[i].token = tokens[i];
        nodes[i].prev = (i > 0) ? &nodes[i - 1] : NULL;
        nodes[i].next = (i < num_of_tokens - 1) ? &nodes[i + 1] : NULL;

        printf("Node %d: Token: %s Prev Token: %s Next Token: %s\n",
               i,
               tokens[i].value ? tokens[i].value : "NULL",
               nodes[i].prev ? nodes[i].prev->token.value : "NULL",
               nodes[i].next ? nodes[i].next->token.value : "NULL");
    }

    return nodes;
}