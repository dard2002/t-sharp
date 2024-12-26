#pragma once

#include <stdio.h>
#include <stdlib.h>

enum { 
    TK_KEYWORD,
    TK_VARIABLE_NAME,
    TK_EOF
};

typedef struct {
  int type;
  char* value;
} Token;

Token* tokenize(char* source_code);