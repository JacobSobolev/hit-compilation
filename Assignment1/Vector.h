#ifndef VECTOR
#define VECTOR

#include <stdlib.h>
#include "TypeDefinitions.h"
#include "Token.h"

typedef struct {
    int index;
	Token* tokens;
    int size;
} Vector;

void CreateVector(Vector* vec);
void TokenAdd(Vector* vec, Token* value);
void TokenDelete(Vector* vec, int index);
void PrintVector(Vector* vec);

#endif