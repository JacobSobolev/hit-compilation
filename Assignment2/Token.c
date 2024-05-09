#include "Token.h"

char* typeDefToLexemeStr(int i){
	char* lexemeMap[]={"Parbegin", "Parend",\
                "Task",\
                "Real", "Integer",\
                "Assigment","Do", "Until", "Od",\
                "Send", "Accept",\
                "Begin","End",\
                "Binary Addition", "Binary Subtraction","Binary Multiplication", "Binary Division",\
                "Equal", "Not Equal", "Greater", "Lesser", "Lesser Equal", "Greater Equal",\
                "Comma","Semicolon", "Round Brcket Left", "Round Braket Right","Curly Braces Left", "Curly Braces Right","Task Parallel","Task Period",\
				"Id",\
                "Integer Number", "Real Number",\
                "End Of File"};
	return lexemeMap[i];
}

char* typeDefToLexemeName(int i){
	char* lexemeMap[]={"parbegin", "parend",\
                "task",\
                "real", "integer",\
                "=","do", "until", "od",\
                "send", "accept",\
                "begin","end",\
                "+", "-","*", "/",\
                "==", "!=", ">", "<", "<=", ">=",\
                ",",";", "(", ")","{", "}","||",".",\
				"id",\
                "integer number", "read number",\
                "EOF"};
	return lexemeMap[i];
}

void PrintToken(Token* t,FILE* file){
    if (t != NULL){
        fprintf(file, "Token from type '%s' was found at line: %d, lexeme: '%s'.\n", typeDefToLexemeStr(t->type), t->lineNumber, t->lexeme);
        // printf("Token from type '%s' was found at line: %d, lexeme: '%s'.\n", typeDefToLexemeStr(t->type), t->lineNumber, t->lexeme);
    }
}
