#include "parserUtils.h"

//Check if token types match
void match(int type, Vector *vec, FILE *file) {
  Token *tok = nextToken(vec, &fileIndex);
  if (tok->type != type) {
    fprintf(file, "Syntax error in line %d: expected '%s' , got '%s' \n",
            tok->lineNumber, typeDefToLexemeName(type), tok->lexeme);
  } else {
    if (tok->type == EOF_) {
      backToken(vec, &fileIndex);
    }
  }
}

//Error recovery 
void errorRecovery(int *followArray, Vector *vec) {
  int size = followArray[0];
  Token *tok = backToken(vec, &fileIndex);
  int i;
  while (1) {
    tok = nextToken(vec, &fileIndex);
    for (i = 1; i <= size; i++) {
      if (tok->type == followArray[i] || tok->type == EOF_) {
        backToken(vec, &fileIndex);
        return;
      }
    }
  }
}

void parseProgram(Vector *vec, StackScope *stack, FILE *yyoutsyn,
                  FILE *yyoutsem) {
  currentTable = pushToStackScope(stack, GlobalScopeIdStr);
  globalTable = currentTable;
  fprintf(yyoutsyn, ruleStrParseProgram);
  parseTaskDefinitions(vec, stack, yyoutsyn, yyoutsem);
  match(PARBEGIN, vec, yyoutsyn);
  parseTaskList(vec, stack, yyoutsyn, yyoutsem);
  match(PAREND, vec, yyoutsyn);
}

//Parsing Task Definitions using all cases, default for syntax error display and error recovery
void parseTaskDefinitions(Vector *vec, StackScope *stack, FILE *yyoutsyn,
                          FILE *yyoutsem) {
  Token *tok;


  fprintf(yyoutsyn, ruleStrParseTaskDefinitions);

  parseTaskDefinition(vec, stack, yyoutsyn, yyoutsem);

  tok = nextToken(vec, &fileIndex);

  switch (tok->type) {
  case SEMICOLON:
    tok = nextToken(vec, &fileIndex);
    switch (tok->type) {
    case TASK:
      backToken(vec, &fileIndex);
      parseTaskDefinitions(vec, stack, yyoutsyn, yyoutsem);
      break;
    case PARBEGIN:
      backToken(vec, &fileIndex);
      break;
    default:
      fprintf(yyoutsyn,
              "Syntax error in line %d: expected '%s' or '%s' , got '%s' \n",
              tok->lineNumber, typeDefToLexemeName(PARBEGIN),
              typeDefToLexemeName(TASK), tok->lexeme);
      errorRecovery(taskDefinitionsFollow, vec);
      break;
    }
    break;
  case PARBEGIN:
    backToken(vec, &fileIndex);
    break;
  default:
    fprintf(yyoutsyn,
            "Syntax error in line %d: expected '%s' or '%s' , got '%s' \n",
            tok->lineNumber, typeDefToLexemeName(SEMICOLON),
            typeDefToLexemeName(PARBEGIN), tok->lexeme);
    errorRecovery(taskDefinitionsFollow, vec);
    break;
  }
}

//Parsing Task Definitions using all cases, default for syntax error display and error recovery
void parseTaskDefinition(Vector *vec, StackScope *stack, FILE *yyoutsyn,
                         FILE *yyoutsem) {
  Token *tok;
  TableRecord *tr;
  Token *tokScopeId;
  Token *tokDeclrationType;
  fprintf(yyoutsyn, ruleParseTaskDefinition);

  tok = nextToken(vec, &fileIndex);

  switch (tok->type) {
  case TASK:
    // match(ID, vec, yyoutsyn);
    tokDeclrationType = duplicateToken(tok);
    // adding variables to the table that wasn't declared in this scope
    tok = nextToken(vec, &fileIndex);
    switch (tok->type) {
    case ID:
      tokScopeId = tok;
      tr = searchRecordInStackScope(stack, tok->lexeme);
      if (tr == NULL) {
        addRecordToTable(currentTable, tokDeclrationType->type, tok->lexeme, -1 , GlobalScopeIdStr);
      } else {
        fprintf(yyoutsem, "id '%s' in line: %d was already declared\n",
                tok->lexeme, tok->lineNumber);
      }

      break;
    default:
      fprintf(yyoutsyn, "Syntax error in line %d: expected '%s', got '%s' \n",
              tok->lineNumber, typeDefToLexemeName(ID), tok->lexeme);
      break;
    }

    deleteToken(tokDeclrationType);

    if (tokScopeId != NULL){
        currentTable = pushToStackScope(stack, tokScopeId->lexeme);
    } else {
      currentTable = pushToStackScope(stack, "_undeclaredTaskID_");
    }

    match(BEGIN_SECTION, vec, yyoutsyn);

    parseDeclarations(vec, stack, yyoutsyn, yyoutsem, NULL);

    match(CURLY_BRACES_LEFT, vec, yyoutsyn);

    parseCommands(vec, stack, yyoutsyn, yyoutsem);

    match(CURLY_BRACES_RIGHT, vec, yyoutsyn);
    match(END_SECTION, vec, yyoutsyn);

    currentTable = popFromStackScope(stack);

    break;
  default:
    fprintf(yyoutsyn, "Syntax error in line %d: expected '%s', got '%s' \n",
            tok->lineNumber, typeDefToLexemeName(TASK), tok->lexeme);
    errorRecovery(taskDefinitionsFollow, vec);
    break;
  }
}

//Parsing Declarations using all cases, default for syntax error display and error recovery
void parseDeclarations(Vector *vec, StackScope *stack, FILE *yyoutsyn,
                       FILE *yyoutsem, int *numOfDeclared) {
  Token *tok;
  int wasDeclared = 0;

  fprintf(yyoutsyn, ruleParseDeclarations);

  parseDeclaration(vec, stack, yyoutsyn, yyoutsem, &wasDeclared);

  if (wasDeclared == 1 && numOfDeclared != NULL){
    (*numOfDeclared)++;
  }

  tok = nextToken(vec, &fileIndex);

  switch (tok->type) {
  case SEMICOLON:
    tok = nextToken(vec, &fileIndex);
    switch (tok->type) {
    case INTEGER:
    case REAL:
      backToken(vec, &fileIndex);
      parseDeclarations(vec, stack, yyoutsyn, yyoutsem, numOfDeclared);
      break;
    default:
      fprintf(yyoutsyn,
              "Syntax error in line %d: expected '%s' or '%s', got '%s'\n",
              tok->lineNumber, typeDefToLexemeName(INTEGER),
              typeDefToLexemeName(REAL), tok->lexeme);
      errorRecovery(declarationsFollow, vec);
      break;
    }
    break;
  case CURLY_BRACES_LEFT:
  case ROUND_BRACKETS_RIGHT:
    backToken(vec, &fileIndex);
    break;
  default:
    fprintf(
        yyoutsyn,
        "Syntax error in line %d: expected '%s' or '%s' or '%s', got '%s' \n",
        tok->lineNumber, typeDefToLexemeName(SEMICOLON),
        typeDefToLexemeName(CURLY_BRACES_LEFT),
        typeDefToLexemeName(ROUND_BRACKETS_RIGHT), tok->lexeme);
    errorRecovery(declarationsFollow, vec);
    break;
  }
}

//Parsing Declarations using all cases, default for syntax error display and error recovery
void parseDeclaration(Vector *vec, StackScope *stack, FILE *yyoutsyn,
                      FILE *yyoutsem, int *wasDeclared) {
  Token *tok;
  Token *tokDeclarationType;
  TableRecord *tr;

  fprintf(yyoutsyn, ruleParseDeclaration);

  tok = nextToken(vec, &fileIndex);
  switch (tok->type) {
  case INTEGER:
  case REAL:
    // match(ID, vec, yyoutsyn);
    tokDeclarationType = duplicateToken(tok);
    tok = nextToken(vec, &fileIndex);

    switch (tok->type) {
    case ID:
      tr = getRecordFromTable(currentTable, tok->lexeme);
      if (tr == NULL) {

        addRecordToTable(currentTable, tok->type, tok->lexeme,
          tokDeclarationType->type, currentTable->scopeId);

        if (wasDeclared != NULL){
          *wasDeclared = 1;
        }

      } else {
        fprintf(yyoutsem, "id '%s' in line: %d was already declared\n",
                tok->lexeme, tok->lineNumber);
      }

      break;
    default:
      fprintf(yyoutsyn, "Syntax error in line %d: expected '%s', got '%s' \n",
              tok->lineNumber, typeDefToLexemeName(ID), tok->lexeme);
      break;
    }

    deleteToken(tokDeclarationType);

    break;
  default:
    fprintf(yyoutsyn,
            "Syntax error in line %d: expected '%s' or '%s' , got '%s' \n",
            tok->lineNumber, typeDefToLexemeName(INTEGER),
            typeDefToLexemeName(REAL), tok->lexeme);
    errorRecovery(declarationFollow, vec);
    break;
  }
}

//Parsing Task Lists using all cases, default for syntax error display and error recovery
void parseTaskList(Vector *vec, StackScope *stack, FILE *yyoutsyn,
                   FILE *yyoutsem) {
  Token *tok;
  TableRecord *tr;

  fprintf(yyoutsyn, ruleParseTaskList);

  tok = nextToken(vec, &fileIndex);
  switch (tok->type) {
  case ID:
    // need to check if id declared
    tr = searchRecordInStackScope(stack, tok->lexeme);
    if (tr == NULL) {
      fprintf(yyoutsem, "id '%s' in line: %d wasn't declared\n", tok->lexeme,
              tok->lineNumber);
    }

    tok = nextToken(vec, &fileIndex);
    switch (tok->type) {
    case TASK_PARALLEL:
      parseTaskList(vec, stack, yyoutsyn, yyoutsem);
      break;
    case PAREND:
      backToken(vec, &fileIndex);
      break;
    default:
      fprintf(yyoutsyn,
              "Syntax error in line %d: expected '%s' or '%s' , got '%s' \n",
              tok->lineNumber, typeDefToLexemeName(TASK_PARALLEL),
              typeDefToLexemeName(PAREND), tok->lexeme);
      errorRecovery(taskListFollow, vec);
      break;
    }
    break;
  case PAREND:
    backToken(vec, &fileIndex);
    break;
  default:
    fprintf(yyoutsyn,
            "Syntax error in line %d: expected '%s' or '%s' , got '%s' \n",
            tok->lineNumber, typeDefToLexemeName(ID),
            typeDefToLexemeName(PAREND), tok->lexeme);
    errorRecovery(declarationFollow, vec);
    break;
  }
}

//Parsing Commands using all cases, default for syntax error display and error recovery
void parseCommands(Vector *vec, StackScope *stack, FILE *yyoutsyn,
                   FILE *yyoutsem) {
  Token *tok;

  fprintf(yyoutsyn, ruleParseCommands);

  parseCommand(vec, stack, yyoutsyn, yyoutsem);

  tok = nextToken(vec, &fileIndex);
  switch (tok->type) {
  case SEMICOLON:
    tok = nextToken(vec, &fileIndex);
    switch (tok->type) {
    case ID:
    case DO:
    case SEND:
    case ACCEPT:
    case BEGIN_SECTION:
      backToken(vec, &fileIndex);
      parseCommands(vec, stack, yyoutsyn, yyoutsem);
      break;
    case UNTIL:
    case CURLY_BRACES_RIGHT:
      backToken(vec, &fileIndex);
      break;
    default:
      fprintf(yyoutsyn,
              "Syntax error in line %d: expected '%s' or '%s' or '%s' "
              "or '%s' or '%s', got '%s' \n",
              tok->lineNumber, typeDefToLexemeName(ID), typeDefToLexemeName(DO),
              typeDefToLexemeName(SEND), typeDefToLexemeName(ACCEPT),
              typeDefToLexemeName(BEGIN_SECTION), tok->lexeme);
      errorRecovery(commandsFollow, vec);
      break;
    }
    break;
  case CURLY_BRACES_RIGHT:
  case UNTIL:
    backToken(vec, &fileIndex);
    break;
  default:
    fprintf(
        yyoutsyn,
        "Syntax error in line %d: expected '%s' or '%s' or '%s', got '%s' \n",
        tok->lineNumber, typeDefToLexemeName(SEMICOLON),
        typeDefToLexemeName(CURLY_BRACES_RIGHT), typeDefToLexemeName(UNTIL),
        tok->lexeme);
    errorRecovery(commandsFollow, vec);
    break;
  }
}

//Parsing Commands using all cases, default for syntax error display and error recovery
void parseCommand(Vector *vec, StackScope *stack, FILE *yyoutsyn,
                  FILE *yyoutsem) {
  Token *tok;
  Token *tokIdT;
  TableRecord *tr;
  int isDefinedExpression = 1;
  int expressionType = EXPRESSION_NONE;
  int numOfDeclared = 0;

  fprintf(yyoutsyn, ruleParseCommand);

  tok = nextToken(vec, &fileIndex);
  switch (tok->type) {
  case ID:
    fprintf(yyoutsyn, ruleParseCommand1);
    // need to check if was declared
    tr = searchRecordInStackScope(stack, tok->lexeme);
    if (tr == NULL) {
      fprintf(yyoutsem, "id '%s' in line: %d wasn't declared\n", tok->lexeme,
              tok->lineNumber);
    } else {
      //check if not signal or task
      if (tr->type == TASK || tr->type == SIGNAL){
        fprintf(yyoutsem, "id '%s' in line: %d type of %s can't be used in left assignment\n", tok->lexeme,
                tok->lineNumber, typeDefToLexemeStr(tr->type));
      }
    }
    tokIdT = duplicateToken(tok);

    tok = nextToken(vec, &fileIndex);
    switch (tok->type) {
    case ASSIGNMENT:
      parseExpression(vec, stack, yyoutsyn, yyoutsem, tokIdT,
          &isDefinedExpression, &expressionType, NULL);

      if (isDefinedExpression == 0){
        fprintf(yyoutsem, "id '%s' in line: %d was assigned undeclared variable\n", tokIdT->lexeme,
                tokIdT->lineNumber);
      }
      tr = searchRecordInStackScope(stack, tokIdT->lexeme);
      if (tr != NULL && tr->attribute != ID_NONE &&
          tr->attribute != RECORD_NONE && expressionType != EXPRESSION_NONE ){
        if (tr->attribute != expressionType){
          fprintf(yyoutsem, "id '%s' in line: %d is type '%s' but was assigned '%s' type expression\n", tokIdT->lexeme,
                  tokIdT->lineNumber, typeDefToLexemeStr(tr->attribute),
                  typeDefToLexemeStr(expressionType));
        }
      }
      deleteToken(tokIdT);
      break;
    default:
      fprintf(yyoutsyn, "Syntax error in line %d: expected '%s', got '%s' \n",
              tok->lineNumber, typeDefToLexemeName(ASSIGNMENT), tok->lexeme);

      break;
    }

    break;
  case DO:
    fprintf(yyoutsyn, ruleParseCommand2);
    parseCommands(vec, stack, yyoutsyn, yyoutsem);

    match(UNTIL, vec, yyoutsyn);

    parseCondition(vec, stack, yyoutsyn, yyoutsem);

    match(OD, vec, yyoutsyn);
    break;

  case SEND:
    fprintf(yyoutsyn, ruleParseCommand3);

    // need to check if the ID were declared
    // match(ID, vec, yyoutsyn);

    tok = nextToken(vec, &fileIndex);
    switch (tok->type) {
    case ID:
      // need to check if it isn't sending iteself
      tokIdT = duplicateToken(tok);
      if (strcmp(tok->lexeme, currentTable->scopeId) != 0){
        tr = searchRecordInStackScope(stack, tok->lexeme);
        if (tr == NULL) {
          fprintf(yyoutsem, "id '%s' in line: %d wasn't declared\n",
                  tok->lexeme, tok->lineNumber);
        }
      } else {
        fprintf(yyoutsem, "id '%s' in line: %d trying to send itself a signal\n", tok->lexeme,
                tok->lineNumber);
      }


      break;
    default:
      fprintf(yyoutsyn, "Syntax error in line %d: expected '%s', got '%s' \n",
              tok->lineNumber, typeDefToLexemeName(ID), tok->lexeme);
      break;
    }

    match(TASK_PERIOD, vec, yyoutsyn);
    // match(ID, vec, yyoutsyn);

    //need to check if singal was defined
    tok = nextToken(vec, &fileIndex);
    switch (tok->type) {
    case ID:

      //check if task id doesn't send signal to itself

      tr = searchRecordInStackScope(stack, tok->lexeme);
      if (tr == NULL) {
        fprintf(yyoutsem, "id '%s' in line: %d wasn't declared\n",
                tok->lexeme, tok->lineNumber);
      } else {
        if (tr->type != SIGNAL) {
          // id not type of SIGNAL
          fprintf(yyoutsem, "id '%s' in line: %d isn't a type of '%s'\n",
                  tok->lexeme, tok->lineNumber, typeDefToLexemeStr(SIGNAL));

        } else if (strcmp(tr->declaredInScope, tokIdT->lexeme) != 0 ) {
          // signal not declared in this scope
          fprintf(yyoutsem, "id '%s' in line: %d isn't declared in scope '%s'\n",
                  tok->lexeme, tok->lineNumber, tokIdT->lexeme);
        }
      }
      deleteToken(tokIdT);
      tokIdT = duplicateToken(tok);



      break;
    default:
      fprintf(yyoutsyn, "Syntax error in line %d: expected '%s', got '%s' \n",
              tok->lineNumber, typeDefToLexemeName(ID), tok->lexeme);
      break;
    }


    match(ROUND_BRACKETS_LEFT, vec, yyoutsyn);
    numOfDeclared = 0;
    parseParamList(vec, stack, yyoutsyn, yyoutsem, &numOfDeclared);

    match(ROUND_BRACKETS_RIGHT, vec, yyoutsyn);

    //check if the same number of parameters

    tr = getRecordFromTable(globalTable, tokIdT->lexeme);
    if (tr != NULL){
      if (tr->attribute != numOfDeclared){
        fprintf(yyoutsem, "id '%s' in line: %d was called with (%d) ids but was declared with (%d)\n",
                tokIdT->lexeme, tokIdT->lineNumber, numOfDeclared, tr->attribute);
      }
    }

    deleteToken(tokIdT);
    break;
  case ACCEPT:
    fprintf(yyoutsyn, ruleParseCommand4);

    // match(ID, vec, yyoutsyn);
    //push the signal id to global table
    tok = nextToken(vec, &fileIndex);
    tokIdT = duplicateToken(tok);
    switch (tok->type) {
    case ID:
      addRecordToTable(globalTable, SIGNAL, tok->lexeme, -1 , currentTable->scopeId);

      break;
    default:
      fprintf(yyoutsyn, "Syntax error in line %d: expected '%s', got '%s' \n",
              tok->lineNumber, typeDefToLexemeName(ID), tok->lexeme);
      break;
    }

    match(ROUND_BRACKETS_LEFT, vec, yyoutsyn);

    numOfDeclared = 0;
    parseDeclarations(vec, stack, yyoutsyn, yyoutsem, &numOfDeclared);

    match(ROUND_BRACKETS_RIGHT, vec, yyoutsyn);

    //assign the number of parameters to the record
    tr = getRecordFromTable(globalTable, tokIdT->lexeme);
    if (tr != NULL){
      tr->attribute = numOfDeclared;
    }

    deleteToken(tokIdT);
    break;
  case BEGIN_SECTION:
    fprintf(yyoutsyn, ruleParseCommand5);
    //push scope
    currentTable = pushToStackScope(stack, currentTable->scopeId);
    parseDeclarations(vec, stack, yyoutsyn, yyoutsem, NULL);

    match(CURLY_BRACES_LEFT, vec, yyoutsyn);

    parseCommands(vec, stack, yyoutsyn, yyoutsem);

    match(CURLY_BRACES_RIGHT, vec, yyoutsyn);
    match(END_SECTION, vec, yyoutsyn);
    currentTable = popFromStackScope(stack);
    //pop scope
    break;
  case CURLY_BRACES_RIGHT:
    backToken(vec, &fileIndex);
    break;
  default:
    fprintf(yyoutsyn,
            "Syntax error in line %d: expected '%s' or '%s' or '%s' or "
            "'%s' or '%s', got '%s' \n",
            tok->lineNumber, typeDefToLexemeName(ID), typeDefToLexemeName(DO),
            typeDefToLexemeName(SEND), typeDefToLexemeName(ACCEPT),
            typeDefToLexemeName(BEGIN_SECTION), tok->lexeme);
    errorRecovery(commandFollow, vec);
    break;
  }
}

//Parsing Expressions using all cases, default for syntax error display and error recovery
void parseExpression(Vector *vec, StackScope *stack, FILE *yyoutsyn,
                     FILE *yyoutsem, Token* leftTokId, int *isDefinedExpression,
                     int *expressionType, int* gotIdOrNumber) {
  Token *tok;
  TableRecord *tr;

  fprintf(yyoutsyn, ruleParseExpression);

  tok = nextToken(vec, &fileIndex);

  switch (tok->type) {

  case ID:
    if (gotIdOrNumber != NULL && (*gotIdOrNumber) == 0){
      *gotIdOrNumber = 1;
    }
    tr = searchRecordInStackScope(stack, tok->lexeme);
    if (tr == NULL){
      fprintf(yyoutsem, "id '%s' in line: %d wasn't declared\n", tok->lexeme,
              tok->lineNumber);
    } else if (tr->attribute == ID_NONE) {
      fprintf(yyoutsem, "id '%s' in line: %d was prviouesly assigned undeclared id and considerd as not declared\n", tok->lexeme,
              tok->lineNumber);
    }
    if (tr == NULL) {
      if (leftTokId != NULL && isDefinedExpression != NULL){
        if (*isDefinedExpression == 1){
          *isDefinedExpression = 0;
        }
      }
    } else {
      // check types
      if (tr != NULL){
        if (tr->attribute == ID_NONE){
          tr = searchRecordInStackScope(stack, leftTokId->lexeme);
          if (tr != NULL){
            tr->attribute = ID_NONE;
          }
        }
        if (tr->attribute != TASK && tr->attribute != SIGNAL){
          if (expressionType != NULL ){
            if (*expressionType == EXPRESSION_NONE){
              *expressionType = tr->attribute;
            } else if (*expressionType == INTEGER_NUMBER && tok->type == REAL_NUMBER){
              *expressionType = tr->attribute;
            }
          }
        } else {
          fprintf(yyoutsem, "id '%s' in line: %d of type: %s can't ne used in expression\n", tok->lexeme,
                  tok->lineNumber, typeDefToLexemeStr(tr->attribute));
        }
      }
    }


    tok = nextToken(vec, &fileIndex);
    switch (tok->type) {
    case BINARY_ADDITION:
    case BINARY_SUBTRACTION:
    case BINARY_MULTIPLICATION:
    case BINARY_DIVISION:
      parseExpression(vec, stack, yyoutsyn, yyoutsem, leftTokId,
         isDefinedExpression, expressionType, gotIdOrNumber);
      break;
    case DO:
    case SEND:
    case ACCEPT:
    case BEGIN_SECTION:
    case CURLY_BRACES_RIGHT:
    case ROUND_BRACKETS_RIGHT:
    case SEMICOLON:
    case COMMA:
      backToken(vec, &fileIndex);
      break;
    default:
      fprintf(yyoutsyn,
              "Syntax error in line %d: expected '%s' or '%s' or '%s' "
              "or '%s', got '%s' \n",
              tok->lineNumber, typeDefToLexemeName(BINARY_ADDITION),
              typeDefToLexemeName(BINARY_SUBTRACTION),
              typeDefToLexemeName(BINARY_MULTIPLICATION),
              typeDefToLexemeName(BINARY_DIVISION), tok->lexeme);
      errorRecovery(expressionFollow, vec);
      break;
    }
    break;
  case INTEGER_NUMBER:
    if (gotIdOrNumber != NULL && (*gotIdOrNumber) == 0){
      *gotIdOrNumber = 1;
    }
    if (expressionType != NULL){
      if (*expressionType == EXPRESSION_NONE ){
        *expressionType = INTEGER;
      }
    }
    break;
  case REAL_NUMBER:
      if (gotIdOrNumber != NULL && (*gotIdOrNumber) == 0){
        *gotIdOrNumber = 1;
      }
      if (expressionType != NULL){
        if (*expressionType == EXPRESSION_NONE || *expressionType == INTEGER_NUMBER){
          *expressionType = REAL;
        }
      }
    break;
  default:
    fprintf(
        yyoutsyn,
        "Syntax error in line %d: expected '%s' or '%s' or '%s', got '%s' \n",
        tok->lineNumber, typeDefToLexemeName(ID),
        typeDefToLexemeName(INTEGER_NUMBER), typeDefToLexemeName(REAL_NUMBER),
        tok->lexeme);
    errorRecovery(expressionFollow, vec);
    break;
  }
}

//Parsing Parameter Lists using all cases, default for syntax error display and error recovery
void parseParamList(Vector *vec, StackScope *stack, FILE *yyoutsyn,
                    FILE *yyoutsem, int* numOfDeclared) {
  Token *tok;
  int isDefinedExpression = 1;
  int gotIdOrNumber = 0;

  fprintf(yyoutsyn, ruleParseParamList);

  parseExpression(vec, stack, yyoutsyn, yyoutsem, NULL, NULL, NULL, &gotIdOrNumber);

  if (gotIdOrNumber == 1 && numOfDeclared != NULL){
      (*numOfDeclared)++;
  }

  tok = nextToken(vec, &fileIndex);

  switch (tok->type) {
  case COMMA:

    parseParamList(vec, stack, yyoutsyn, yyoutsem, numOfDeclared);
    break;
  case ROUND_BRACKETS_RIGHT:
    backToken(vec, &fileIndex);
    break;
  default:
    fprintf(yyoutsyn,
            "Syntax error in line %d: expected '%s' or '%s', got '%s' \n",
            tok->lineNumber, typeDefToLexemeName(COMMA),
            typeDefToLexemeName(ROUND_BRACKETS_RIGHT), tok->lexeme);
    errorRecovery(paramListFollow, vec);
    break;
  }
}

//Parsing Conditions using all cases, default for syntax error display and error recovery
void parseCondition(Vector *vec, StackScope *stack, FILE *yyoutsyn,
                    FILE *yyoutsem) {
  Token *tok;
  TableRecord *tr;

  fprintf(yyoutsyn, ruleParseCondition);

  tok = nextToken(vec, &fileIndex);
  switch (tok->type) {
  case ROUND_BRACKETS_LEFT:
    tok = nextToken(vec, &fileIndex);
    switch (tok->type) {
    case ID:
      //check if declraed
      tr = searchRecordInStackScope(stack, tok->lexeme);
      if (tr == NULL) {
        fprintf(yyoutsem, "!id '%s' in line: %d wasn't declared\n", tok->lexeme,
                tok->lineNumber);
      } else {
        //check if not signal or task
        if (tr->type == TASK || tr->type == SIGNAL){
          fprintf(yyoutsem, "id '%s' in line: %d type of '%s' can't be used in Condition\n", tok->lexeme,
                  tok->lineNumber, typeDefToLexemeStr(tr->type));
        }
      }

      tok = nextToken(vec, &fileIndex);
      switch (tok->type) {
      case EQUAL:
      case NOT_EQUAL:
      case GREATER:
      case LESSER:
      case LESSER_EQUAL:
      case GREATER_EQUAL:
      case ROUND_BRACKETS_LEFT:
        tok = nextToken(vec, &fileIndex);
        switch (tok->type) {
        case ID:
          //check if declraed
          tr = searchRecordInStackScope(stack, tok->lexeme);
          if (tr == NULL) {
            fprintf(yyoutsem, "!id '%s' in line: %d wasn't declared\n", tok->lexeme,
                    tok->lineNumber);
          } else {
            //check if not signal or task
            if (tr->type == TASK || tr->type == SIGNAL){
              fprintf(yyoutsem, "id '%s' in line: %d type of '%s' can't be used in Condition\n", tok->lexeme,
                      tok->lineNumber, typeDefToLexemeStr(tr->type));
            }
          }
          tok = nextToken(vec, &fileIndex);
          switch (tok->type) {

          case ROUND_BRACKETS_RIGHT:
            break;
          default:
            fprintf(yyoutsyn,
                    "Syntax error in line %d: expected '%s', got '%s' \n",
                    tok->lineNumber, typeDefToLexemeName(ROUND_BRACKETS_RIGHT),
                    tok->lexeme);
            errorRecovery(conditionFollow, vec);
            break;
          }
          break;
        default:
          fprintf(yyoutsyn,
                  "Syntax error in line %d: expected '%s', got '%s' \n",
                  tok->lineNumber, typeDefToLexemeName(ID), tok->lexeme);
          errorRecovery(conditionFollow, vec);
          break;
        }
        break;
      default:
        fprintf(yyoutsyn,
                "Syntax error in line %d: expected '%s' or '%s' or '%s' or "
                "'%s' or '%s' or '%s', got '%s' \n",
                tok->lineNumber, typeDefToLexemeName(EQUAL),
                typeDefToLexemeName(NOT_EQUAL), typeDefToLexemeName(GREATER),
                typeDefToLexemeName(LESSER), typeDefToLexemeName(LESSER_EQUAL),
                typeDefToLexemeName(GREATER_EQUAL), tok->lexeme);
        errorRecovery(conditionFollow, vec);
        break;
      }

      break;

    default:
      fprintf(yyoutsyn, "Syntax error in line %d: expected '%s', got '%s' \n",
              tok->lineNumber, typeDefToLexemeName(ID), tok->lexeme);
      errorRecovery(conditionFollow, vec);
      break;
    }

    break;
  default:
    fprintf(yyoutsyn, "Syntax error in line %d: expected '%s', got '%s' \n",
            tok->lineNumber, typeDefToLexemeName(ROUND_BRACKETS_LEFT),
            tok->lexeme);
    errorRecovery(conditionFollow, vec);
    break;
  }
}
