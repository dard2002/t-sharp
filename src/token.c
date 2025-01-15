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
        
        // Fix this dumbass if statement later
        if(strcmp(token, "void") != 0 || strcmp(token, "int") != 0 || strcmp(token, "bool") != 0 || strcmp(token, "string") != 0 || strcmp(token, "double") != 0 || strcmp(token, "float") != 0 || strcmp(token, "class") != 0 || strcmp(token, "struct") != 0 || strcmp(token, "public") != 0 || strcmp(token, "private") != 0 || strcmp(token, "return") != 0) {
            tokens[idx].type = TK_TYPE;
        } else {
            tokens[idx].type = TK_VARIABLE_NAME;
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