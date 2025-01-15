#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"
#include "node.h"

int main() {
    FILE* file;
    int file_contents_size = 10;
    int bytes_read = 0;
    char* file_contents = malloc(file_contents_size * sizeof(char));

    file = fopen("examples/hello_world.tsharp", "r");
    while (fgets(file_contents + bytes_read, file_contents_size - bytes_read, file)) {
        bytes_read += strlen(file_contents + bytes_read);
        if (bytes_read >= file_contents_size - 1) {
            file_contents_size += 10;
            file_contents = realloc(file_contents, file_contents_size * sizeof(char));
        }
    }

    Token* tokens = tokenize(file_contents);
    Node* nodes = parse(tokens);

    free(nodes);
    nodes = NULL;

    free(tokens);
    tokens = NULL;

    free(file_contents);
    file_contents = NULL;

    fclose(file);

    return 0;
}
