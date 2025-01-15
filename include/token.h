#pragma once

#include <stdio.h>
#include <stdlib.h>

// Types of tokens defined in T#
enum { 
  TK_TYPE,
  TK_FUNCTION_NAME,
  TK_BLOCK_START,
  TK_FUNCTION_ARGS,
  TK_BLOCK_END,
  TK_VARIABLE_NAME,
  TK_OPERATOR,
  TK_LINE_END
};

typedef struct {
  int type;
  char* value;
} Token;

Token* tokenize(char* source_code);