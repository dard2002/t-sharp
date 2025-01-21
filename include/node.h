#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h>
#include "token.h"

typedef struct Node Node; // Forward declaration

struct Node {
  Token token;
  Node* prev;
  Node* next;
};

Node* create_nodes(Token* tokens, int num_of_tokens);

#endif // NODE_H