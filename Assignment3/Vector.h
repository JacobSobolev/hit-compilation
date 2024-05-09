#ifndef VECTOR
#define VECTOR

#include "Token.h"
#include <stdlib.h>

typedef struct {
  int index;
  int size;
  Token **tokens;
} Vector;

void CreateVector(Vector *);
void DeleteVector(Vector *);
void TokenAdd(Vector *, Token *);
void TokenDelete(Vector *, int);

#endif
