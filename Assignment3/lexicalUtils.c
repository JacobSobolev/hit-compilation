#include "lexicalUtils.h"

//Token creation and storing
Token* createAndStoreToken(Vector *vec, int type, char* lexeme, int lineNumber)
{
    Token* tok = (Token*)malloc(sizeof(Token));
    tok->lineNumber = lineNumber;
    tok->type = type;
    tok->lexeme = lexeme;
    TokenAdd(vec, tok);
    return tok;
}

//Duplicate Token implementation
Token* duplicateToken(Token *tok)
{
  Token* newTok = (Token*)malloc(sizeof(Token));
  newTok->lineNumber = tok->lineNumber;
  newTok->type = tok->type;

  newTok->lexeme = malloc(sizeof(char*) * strlen(tok->lexeme) + 1);
  strcpy(newTok->lexeme, tok->lexeme);
  return newTok;
}
void deleteToken(Token* tok)
{
  free(tok->lexeme);
  free(tok);
}

//Next Token implementation
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

//Back Token implementation
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

//Error display of the character, type and line
void PrintLexError(char* lexeme, int lineNumber, FILE* file){
    fprintf(file, "The character '%s' at line: %d does not begin any legal token in the language.\n", lexeme, lineNumber);
}
