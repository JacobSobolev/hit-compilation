#ifndef PARSER_UTILS
#define PARSER_UTILS

#include "lexemesDefinitions.h"
#include "lexicalUtils.h"
#include "Vector.h"
#include "Token.h"

int taskDefinitionsFollow[3] = {2, SEMICOLON, PARBEGIN};

int declarationsFollow[3] = {2, CURLY_BRACES_LEFT, ROUND_BRACKETS_RIGHT};
int declarationFollow[4] = {3, CURLY_BRACES_LEFT, ROUND_BRACKETS_RIGHT, SEMICOLON};

int taskListFollow[2] = {1,  PAREND};

int commandsFollow[3] = {2, UNTIL, CURLY_BRACES_RIGHT};
int commandFollow[4] = {3,  UNTIL, CURLY_BRACES_RIGHT, SEMICOLON};

int paramListFollow[2] = {1,  ROUND_BRACKETS_RIGHT};
int expressionFollow[4] = {3,  COMMA, ROUND_BRACKETS_RIGHT,CURLY_BRACES_RIGHT}; 
int conditionFollow[2] = {1,  OD}; 


void match(int, Vector *, FILE*);
void errorRecovery(int *, Vector *);

void parseProgram(Vector *, FILE*);

void parseTaskDefinitions(Vector *, FILE*);
void parseTaskDefinition(Vector *, FILE*);

void parseDeclarations(Vector *, FILE*);
void parseDeclaration(Vector *, FILE*);

void parseTaskList(Vector *, FILE*);

void parseCommands(Vector *, FILE*);
void parseCommand(Vector *, FILE*);

void parseParamList(Vector *, FILE*);

void parseExpression(Vector *, FILE*);

void parseCondition(Vector *, FILE*);

#endif
