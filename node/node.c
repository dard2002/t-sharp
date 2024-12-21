#include "stdio.h"
#include "stdlib.h"
#include "../token/token.h"
#include "node.h"

// WORK IN PROGRESS
Node* parse(Token* tokens) {
    int numOfTokens = sizeof(tokens) / sizeof(tokens[0]);
    Node* nodes = malloc(numOfTokens * sizeof(Node));

    printf("%d\n", numOfTokens);

    for(int i = 0; i < numOfTokens; ++i) {
        Token nextToken;
        Token previousToken;
        Node* prev = malloc(sizeof(Node));
        Node* next = malloc(sizeof(Node));

        if(i == 0) {
            nextToken = tokens[i + 1];
        }

        else if(i == numOfTokens) {
            previousToken = tokens[i - 1];
        }

        else {
            previousToken = tokens[i - 1];
            nextToken = tokens[i + 1];
        }
    }

    return nodes;
}