#include "token.h"

// List of keywords defined in T#
const char* keywords[] = {
  "void",
  "int",
  "string",
  "float",
  "double",
  "char",
  "bool",
  "enum",
  "private",
  "class",
  "return",
  "if",
  "else",
  "while",
  "for"
};

const int num_of_keywords = sizeof(keywords) / sizeof(keywords[0]);
