#include "Token.h"

char* typeDefToLexemeStr(int i){

	return DefToLexemeStrMap[i];
}

char* typeDefToLexemeName(int i){

	return DefToLexemeNameMap[i];
}

//Dispay of the token, type and line
void PrintToken(Token* t, FILE* file){
    if (t != NULL){
        fprintf(file, "Token from type '%s' was found at line: %d, lexeme: '%s'.\n", typeDefToLexemeStr(t->type), t->lineNumber, t->lexeme);
    }
}
