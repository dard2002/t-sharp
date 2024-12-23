#include "stdio.h"
#include "stdlib.h"
#include "../token/token.h"
#include "node.h"

Node* parse(Token* tokens) {
    int num_of_tokens = 0;
    while(tokens[num_of_tokens].type != TK_EOF) {
        num_of_tokens++;
    }

    Node* nodes = malloc(num_of_tokens * sizeof(Node));
    Node* prev = malloc(sizeof(Node));
    Node* next = malloc(sizeof(Node));

    for(int i = 0; i < num_of_tokens; ++i) {
        nodes[i].token = tokens[i];

        if(i == 0) {
            next->token = tokens[i + 1];
            nodes[i].next = next;
        }

        else if(i == num_of_tokens) {
            prev->token = tokens[i - 1];
            nodes[i].prev = prev;
        }

        else {
            prev->token = tokens[i - 1];
            next->token = tokens[i + 1];
        }

        printf("Node %d: Token: %s Prev Token: %s Next Token: %s\n", i, tokens[i].value, prev->token.value, next->token.value);
    }

    free(prev);
    prev = NULL;

    free(next);
    next = NULL;

    return nodes;
}

