#ifndef TOKEN
#define TOKEN

typedef struct {
    int type;
    char* lexeme;
    int lineNumber;
} Token;


char* typeDefToLexemeStr(int i);
char* typeDefToLexemeName(int i);
void PrintToken(Token *, FILE*);

#endif