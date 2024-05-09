#include "lexicalUtils.h"


void createAndStoreToken(Vector *vec, int type, char* lexeme, int lineNumber)
{	
    Token* tok = (Token*)malloc(sizeof(Token));
    tok->lineNumber = lineNumber;
    tok->type = type;
    tok->lexeme = lexeme;
    TokenAdd(vec, tok);
}

Token* nextToken(Vector* vec, int* fileIndex)
{
   Token* tok;
   if((*fileIndex) == vec->index)
   {
        if (yylex())
        {
            tok = vec->tokens[(*fileIndex)++];
        }
		else
        {
            return NULL;
        }
         
   }
   else
   {
        tok = vec->tokens[(*fileIndex)++];
   }

   return tok;
}

Token* backToken(Vector *vec, int* fileIndex)
{
    Token* tok;
    if((*fileIndex) >= 2)
    {
        tok = vec->tokens[(--(*fileIndex)) - 1];
    }
    else if (vec->tokens[(*fileIndex) - 2] == NULL)
    {
        return NULL;
    }

    return tok;
}

void PrintError(char* lexeme, int lineNumber, FILE* file){
    fprintf(file, "The character '%s' at line: %d does not begin any legal token in the language.\n", lexeme, lineNumber);
    // printf("The character '%s' at line: %d does not begin any legal token in the language.\n", lexeme, lineNumber);
}