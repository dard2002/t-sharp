#pragma once

#include <stdio.h>
#include <stdlib.h>

#ifndef TOKEN_H
#define TOKEN_H

typedef struct {
  int type;
  char* value;
} Token;

Token *tokenize(char *source_code);

// Types of tokens defined in T#
enum
{
  TK_KEYWORD,
  TK_FUNCTION_NAME,
  TK_BLOCK_START,
  TK_FUNCTION_ARGS,
  TK_BLOCK_END,
  TK_VARIABLE_NAME,
  TK_OPERATOR,
  TK_VARIABLE_VALUE,
  TK_LINE_END,
  TK_EOF
};

extern const char *keywords[];
extern const int num_of_keywords;

extern const char *operators[];
extern const int num_of_operators;

#endif
