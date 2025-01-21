#include "token.h"

// List of operators defined in T#
const char* operators[] = {
  "+",
  "-",
  "*",
  "/",
  "++",
  "--",
  "&&",
  "||",
  "=",
  "=="
};

const int num_of_operators = sizeof(operators) / sizeof(operators[0]);