#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"
#include "node.h"
#include "interpreter.h"

int main(int argc, char *argv[]) {
    FILE* file;
    int file_contents_size = 10;
    int bytes_read = 0;
    char* file_contents = malloc(file_contents_size * sizeof(char));

    if (argv[1] == NULL) {
        printf("Error: A T# program to run has not been provided as an argument!\nYou need to specify a valid T# program to run, for example: tsharp ./examples/hello_world.tsharp. Terminating...\n");
        return 1;
    }
    
    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: The T# program %s was not found! Terminating...\n", argv[1]);
        return 1;
    }
    
    while (fgets(file_contents + bytes_read, file_contents_size - bytes_read, file)) {
        bytes_read += strlen(file_contents + bytes_read);
        if (bytes_read >= file_contents_size - 1) {
            file_contents_size += 10;
            file_contents = realloc(file_contents, file_contents_size * sizeof(char));
        }
    }

    Token* tokens = tokenize(file_contents);

    // Count the number of tokens
    int num_of_tokens = 0;
    while (tokens[num_of_tokens].type != TK_EOF) {
        num_of_tokens++;
    }

    // Include the TK_EOF token in the count
    num_of_tokens++;

    Node* nodes = create_nodes(tokens, num_of_tokens);

    int result = run(nodes, num_of_tokens);

    free(tokens);
    tokens = NULL;

    free(nodes);
    nodes = NULL;

    free(file_contents);
    file_contents = NULL;

    fclose(file);

    return result;
}