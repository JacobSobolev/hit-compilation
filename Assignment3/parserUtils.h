#ifndef PARSER_UTILS
#define PARSER_UTILS

#include "Token.h"
#include "Vector.h"
#include "lexemesDefinitions.h"
#include "lexicalUtils.h"
#include "StackScope.h"

Table* currentTable;
Table* globalTable;

const char* GlobalScopeIdStr = "_GLOBAL_";

int taskDefinitionsFollow[3] = {2, SEMICOLON, PARBEGIN};

int declarationsFollow[3] = {2, CURLY_BRACES_LEFT, ROUND_BRACKETS_RIGHT};
int declarationFollow[4] = {3, CURLY_BRACES_LEFT, ROUND_BRACKETS_RIGHT,
                            SEMICOLON};

int taskListFollow[2] = {1, PAREND};

int commandsFollow[3] = {2, UNTIL, CURLY_BRACES_RIGHT};
int commandFollow[4] = {3, UNTIL, CURLY_BRACES_RIGHT, SEMICOLON};

int paramListFollow[2] = {1, ROUND_BRACKETS_RIGHT};
int expressionFollow[4] = {3, COMMA, ROUND_BRACKETS_RIGHT, CURLY_BRACES_RIGHT};
int conditionFollow[2] = {1, OD};

const char *ruleStrParseProgram = "Rule: PROGRAM -> TASK_DEFINITIONS; parbegin TASK_LIST parend\n";
const char *ruleStrParseTaskDefinitions = "Rule: TASK_DEFINITIONS -> TASK_DEFINITION | TASK_DEFINITION; TASK_DEFINITIONS\n";
const char *ruleParseTaskDefinition = "Rule: TASK_DEFINITION -> task id begin DECLARATIONS { COMMANDS } end \n";
const char *ruleParseDeclarations = "Rule: DECLARATIONS-> DECLARATION  |  DECLARATION; DECLARATIONS\n";
const char *ruleParseDeclaration = "Rule: DECLARATION -> integer  id   |  real id \n";
const char *ruleParseTaskList = "Rule: TASK_LIST -> task_id ||  TASK_LIST\n";
const char *ruleParseCommands = "Rule: COMMANDS -> COMMAND  | COMMAND; COMMANDS  \n";
const char *ruleParseCommand = "Rule: COMMAND -> id = EXPRESSION | do COMMANDS until CONDITION od | send task_id . signal_id (PARAM_LIST) | accept signal_id (DECLARATIONS) | begin DECLARATIONS { COMMANDS } end  \n";
const char *ruleParseCommand1 = "Rule: id = EXPRESSION \n";
const char *ruleParseCommand2 = "Rule: do COMMANDS until CONDITION od \n";
const char *ruleParseCommand3 = "Rule: end task_id . signal_id (PARAM_LIST) \n";
const char *ruleParseCommand4 = "Rule: accept signal_id (DECLARATIONS) \n";
const char *ruleParseCommand5 = "Rule: begin DECLARATIONS { COMMANDS } end \n";
const char* ruleParseExpression = "Rule: EXPRESSION \n";
const char* ruleParseParamList = "Rule: PARAM_LIST -> EXPRESSION  |  EXPRESSION, PARAM_LIST  \n";
const char* ruleParseCondition =  "Rule: CONDITION -> (id  rel_op  id)  \n";


void match(int type, Vector *vec, FILE *file);
void errorRecovery(int *followArray, Vector *vec);

void parseProgram(Vector *vec, StackScope *stack, FILE *yyoutsyn, FILE *yyoutsem);

void parseTaskDefinitions(Vector *vec, StackScope *stack, FILE *yyoutsyn, FILE *yyoutsem);
void parseTaskDefinition(Vector *vec, StackScope *stack, FILE *yyoutsyn, FILE *yyoutsem);

void parseDeclarations(Vector *vec, StackScope *stack, FILE *yyoutsyn, FILE *yyoutsem, int *numOfDeclared);
void parseDeclaration(Vector *vec, StackScope *stack, FILE *yyoutsyn, FILE *yyoutsem, int *wasDeclared);

void parseTaskList(Vector *vec, StackScope *stack, FILE *yyoutsyn, FILE *yyoutsem);

void parseCommands(Vector *vec, StackScope *stack, FILE *yyoutsyn, FILE *yyoutsem);
void parseCommand(Vector *vec, StackScope *stack, FILE *yyoutsyn, FILE *yyoutsem);

void parseParamList(Vector *vec, StackScope *stack, FILE *yyoutsyn, FILE *yyoutsem, int* numOfDeclared);

void parseExpression(Vector *vec, StackScope *stack, FILE *yyoutsyn, FILE *yyoutsem,
  Token* leftTokId, int *isDefinedExpression, int *expressionType, int *gotIdOrNumber);

void parseCondition(Vector *vec, StackScope *stack, FILE *yyoutsyn, FILE *yyoutsem);

#endif
