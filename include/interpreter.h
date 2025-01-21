#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "node.h"
#include "int.h"

extern Integer** integers;
extern int num_of_integers;

int run(Node* nodes, int num_of_tokens);

#endif