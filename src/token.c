#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"

Token* tokenize(char* source_code) {
    int idx = 0;
    int character_count = 0;
    int size = 10;
    Token* tokens = malloc(size * sizeof(Token));
    if (!tokens) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    
    char* token = strtok(source_code, " ");
    while (token != NULL) {
        character_count += strlen(token);
        if (character_count == size) {
            size += 10;
            tokens = realloc(tokens, size * sizeof(Token));
            if (!tokens) {
                fprintf(stderr, "Memory reallocation failed\n");
                exit(EXIT_FAILURE);
            }
        }

        int is_keyword = 0;
        for (int i = 0; i < num_of_keywords; ++i) {
            if (strcmp(token, keywords[i]) == 0) {
                is_keyword = 1;
                break;
            }
        }

        int is_operator = 0;
        for (int i = 0; i < num_of_operators; ++i) {
            if (strcmp(token, operators[i]) == 0) {
                is_operator = 1;
                break;
            }
        }

        // Check for semicolon
        char* semicolon_pos = strchr(token, ';');
        if (semicolon_pos != NULL) {
            // Handle the part before the semicolon
            if (semicolon_pos != token) {
                *semicolon_pos = '\0';
                tokens[idx].value = token;
                if (is_keyword) {
                    tokens[idx].type = TK_KEYWORD;
                } else if (is_operator) {
                    tokens[idx].type = TK_OPERATOR;
                } else if (idx > 0 && tokens[idx - 1].type == TK_OPERATOR) {
                    tokens[idx].type = TK_VARIABLE_VALUE;
                } else {
                    tokens[idx].type = TK_VARIABLE_NAME;
                }
                printf("Token %d: Type %d, Value %s\n", idx, tokens[idx].type, tokens[idx].value);
                ++idx;
            }

            // Handle the semicolon
            tokens[idx].type = TK_LINE_END;
            tokens[idx].value = ";";
            printf("Token %d: Type %d, Value %s\n", idx, tokens[idx].type, tokens[idx].value);
            ++idx;
        } else if (strcmp(token, "{") == 0) {
            tokens[idx].type = TK_BLOCK_START;
            tokens[idx].value = token;
            printf("Token %d: Type %d, Value %s\n", idx, tokens[idx].type, tokens[idx].value);
            ++idx;
        } else if (strcmp(token, "}") == 0) {
            tokens[idx].type = TK_BLOCK_END;
            tokens[idx].value = token;
            printf("Token %d: Type %d, Value %s\n", idx, tokens[idx].type, tokens[idx].value);
            ++idx;
        } else {
            // Handle the token normally
            tokens[idx].value = token;
            if (is_keyword) {
                tokens[idx].type = TK_KEYWORD;
            } else if (is_operator) {
                tokens[idx].type = TK_OPERATOR;
            } else if (idx > 0 && tokens[idx - 1].type == TK_OPERATOR) {
                tokens[idx].type = TK_VARIABLE_VALUE;
            } else {
                tokens[idx].type = TK_VARIABLE_NAME;
            }
            printf("Token %d: Type %d, Value %s\n", idx, tokens[idx].type, tokens[idx].value);
            ++idx;
        }

        token = strtok(NULL, " ");
    }

    // Mark the end of the tokens array
    tokens[idx].type = TK_EOF;
    tokens[idx].value = NULL;

    return tokens;
}