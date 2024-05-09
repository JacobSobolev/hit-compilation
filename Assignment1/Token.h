#ifndef TOKEN
#define TOKEN


typedef struct {
    int type;
    char* lexeme;
    int lineNumber;
} Token;

void PrintToken(Token* t);

#endif