#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "token/token.h"
#include "node/node.h"

int main() {
    FILE* file;
    int fileContentsSize = 10;
    int bytesRead = 0;
    char* fileContents = malloc(fileContentsSize * sizeof(char));

    file = fopen("examples/hello_world.tsharp", "r");
    while (fgets(fileContents + bytesRead, fileContentsSize - bytesRead, file)) {
        bytesRead += strlen(fileContents + bytesRead);
        if (bytesRead >= fileContentsSize - 1) {
            fileContentsSize += 10;
            fileContents = realloc(fileContents, fileContentsSize * sizeof(char));
        }
    }

    Token* tokens = tokenize(fileContents);
    printf("%lu\n", sizeof(*tokens) / sizeof(tokens[0]));
    Node* nodes = parse(tokens);

    free(nodes);
    nodes = NULL;

    free(tokens);
    tokens = NULL;

    fclose(file);

    return 0;
}