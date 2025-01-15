#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"

Token* tokenize(char* source_code) {
    int idx = 0;
    int character_count = 0;
    int size = 10;
    Token* tokens = malloc(size * sizeof(Token));
    
    char* token = strtok(source_code, " ");
    while (token != NULL) {
        character_count += strlen(token);
        if (character_count == size) {
            size += 10;
            tokens = realloc(tokens, size * sizeof(Token));
        }

        int is_keyword = 0;
        for (int i = 0; i < sizeof(keywords); ++i) {
            if(strcmp(token, keywords[i]) == 0) {
                is_keyword = 1;
                break;
            }
        }

        if (is_keyword) {
            tokens[idx].type = TK_KEYWORD;
        }

        tokens[idx].value = token;

        ++idx;
        token = strtok(NULL, " ");
    }

    if(idx >= size) {
        size += 1;
        tokens = realloc(tokens, size * sizeof(Token));
    }

    tokens[idx].value = NULL;
    tokens[idx].type = TK_EOF;

    free(token);
    token = NULL;

    return tokens;
}