#ifndef LEXICAL_UTILS
#define LEXICAL_UTILS

#include "Vector.h"

int lineNumber = 1;
int fileIndex = 0;

void createAndStoreToken(Vector *, int, char*, int);
Token* nextToken(Vector*, int*);
Token* backToken(Vector*, int*);
void PrintError(char*, int, FILE*);

#endif