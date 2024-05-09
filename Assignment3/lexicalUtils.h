#ifndef LEXICAL_UTILS
#define LEXICAL_UTILS

#include "Vector.h"

int lineNumber = 1;
int fileIndex = 0;
int preformSemanitc = 0;

Token* createAndStoreToken(Vector *, int, char*, int);
Token *duplicateToken(Token *tok);
void deleteToken(Token *tok);
Token* nextToken(Vector*, int*);
Token* backToken(Vector*, int*);
void PrintLexError(char*, int, FILE*);

#endif
