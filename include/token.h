#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int type;
  char* value;
} Token;

Token* tokenize(char* source_code);

// Types of tokens defined in T#
enum { 
  TK_KEYWORD,
  TK_FUNCTION_NAME,
  TK_BLOCK_START,
  TK_FUNCTION_ARGS,
  TK_BLOCK_END,
  TK_VARIABLE_NAME,
  TK_OPERATOR,
  TK_LINE_END,
  TK_EOF
};

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
};