#ifndef INT_H
#define INT_H

typedef struct {
    char* name;
    int value;
} Integer;

Integer* create_int(char* name, int value);
void free_int(Integer*);

#endif // INT_H
