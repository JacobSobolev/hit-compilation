#ifndef VECTOR
#define VECTOR

#include <stdlib.h>
#include "Token.h"

typedef struct {
    int index;
	Token** tokens;
    int size;
} Vector;


void CreateVector(Vector*);
void DeleteVector(Vector*);
void TokenAdd(Vector*, Token*);
void TokenDelete(Vector*, int);

#endif