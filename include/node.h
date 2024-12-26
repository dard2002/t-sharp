#include <stdio.h>
#include <stdlib.h>
#include "token.h"

typedef struct Node {
  Token token;
  struct Node* prev;
  struct Node* next;
} Node;

Node* parse(Token* tokens);
