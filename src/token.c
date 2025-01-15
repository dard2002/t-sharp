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
        for (int i = 0; i < num_of_keywords; ++i) {
            if(strcmp(token, keywords[i]) == 0) {
                is_keyword = 1;
                break;
            }
        }

        int is_operator = 0;
        for (int i = 0; i < num_of_operators; ++i) {
            if(strcmp(token, operators[i]) == 0) {
                is_operator = 1;
                break;
            }
        }

        // Assign token types
        if (is_keyword) {
            tokens[idx].type = TK_KEYWORD;
        } else if (is_operator) {
            tokens[idx].type = TK_OPERATOR;
        } else if (strcmp(token, ";")) {
            tokens[idx].type = TK_LINE_END;
        } else {
            tokens[idx].type = TK_VARIABLE_NAME;
        }

        tokens[idx].value = token;

        printf("Token %d: Type %d, Value %s\n", idx, tokens[idx].type, tokens[idx].value);
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