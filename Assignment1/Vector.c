#include "Vector.h"

void CreateVector(Vector *vec)
{
    vec->index = 0;
    vec->tokens = NULL;
    vec->size = 0;
}

void TokenAdd(Vector *vec, Token *value)
{
    char *lexem = (*value).lexeme;
    vec->index++;
    //If our vector got overflown
    if (vec->index > vec->size)
    {
        vec->size = (++vec->size) * 2;
        vec->tokens = realloc(vec->tokens, sizeof(Token) * (vec->size));
    }

    vec->tokens[vec->index - 1].lexeme = (char *)malloc(strlen(lexem) + 1);
    //Copy values to current tocken in our vector
    strcpy(vec->tokens[vec->index - 1].lexeme, lexem);
    vec->tokens[vec->index - 1].type = (*value).type;
    vec->tokens[vec->index - 1].lineNumber = (*value).lineNumber;
}

void TokenDelete(Vector *vec, int index)
{
    int i;
    //the token isn't int the vector top kek
    if (index < 0 || index >= vec->size)
    {
        return;
    }
    //move evertything back 
    for (i = index; i < vec->size - 1; i++)
    {
        vec->tokens[i] = vec->tokens[i + 1];
    }
    //the last token is duplicated
    vec->size--;
    vec->tokens = realloc(vec->tokens, sizeof(Token) * vec->size);
}



void PrintVector(Vector *vec)
{
    int i;
    for (i = 0; i < vec->index; i++)
    {
        PrintToken(&(vec->tokens[i]));
    }
}
