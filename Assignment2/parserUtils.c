#include "parserUtils.h"

void match(int type, Vector *vec, FILE *file)
{
    Token *tok = nextToken(vec, &fileIndex);
    if (tok->type != type)
    {
        // printf("Syntax error in line %d: expected '%s' , got '%s' \n",
        //        tok->lineNumber, typeDefToLexemeName(type), typeDefToLexemeName(tok->type));
        fprintf(file, "Syntax error in line %d: expected '%s' , got '%s' \n",
                tok->lineNumber, typeDefToLexemeName(type), tok->lexeme);
    }
    else
    {
        if (tok->type == EOF_)
        {
            backToken(vec, &fileIndex);
        }
    }
}

void errorRecovery(int *followArray, Vector *vec)
{
    int size = followArray[0];
    Token *tok = backToken(vec, &fileIndex);
    int i;
    while (1)
    {
        tok = nextToken(vec, &fileIndex);
        for (i = 1; i <= size; i++)
        {
            if (tok->type == followArray[i] || tok->type == EOF_)
            {
                backToken(vec, &fileIndex);
                return;
            }
        }
    }
}

void parseProgram(Vector *vec, FILE *file)
{
    // printf("Rule: PROGRAM -> TASK_DEFINITIONS; parbegin TASK_LIST parend\n");
    fprintf(file, "Rule: PROGRAM -> TASK_DEFINITIONS; parbegin TASK_LIST parend\n");
    parseTaskDefinitions(vec, file);
    match(PARBEGIN, vec, file);
    parseTaskList(vec, file);
    match(PAREND, vec, file);
}

void parseTaskDefinitions(Vector *vec, FILE *file)
{
    Token *tok;

    // printf("Rule: TASK_DEFINITIONS -> TASK_DEFINITION | TASK_DEFINITION ; TASK_DEFINITIONS\n");
    fprintf(file, "Rule: TASK_DEFINITIONS -> TASK_DEFINITION | TASK_DEFINITION ; TASK_DEFINITIONS\n");

    parseTaskDefinition(vec, file);

    tok = nextToken(vec, &fileIndex);

    switch (tok->type)
    {
    case SEMICOLON:
        tok = nextToken(vec, &fileIndex);
        switch (tok->type)
        {
        case TASK:
            backToken(vec, &fileIndex);
            parseTaskDefinitions(vec, file);
            break;
        case PARBEGIN:
            backToken(vec, &fileIndex);
            break;
        default:
            // printf("Syntax error in line %d: expected '%s' or '%s' , got '%s' \n",
            //        tok->lineNumber, typeDefToLexemeName(PARBEGIN), typeDefToLexemeName(TASK), typeDefToLexemeName(tok->type));
            fprintf(file, "Syntax error in line %d: expected '%s' or '%s' , got '%s' \n",
                    tok->lineNumber, typeDefToLexemeName(PARBEGIN), typeDefToLexemeName(TASK), tok->lexeme);
            errorRecovery(taskDefinitionsFollow, vec);
            break;
        }
        break;
    case PARBEGIN:
        backToken(vec, &fileIndex);
        break;
    default:
        // printf("Syntax error in line %d: expected '%s' or '%s' , got '%s' \n",
        //        tok->lineNumber, typeDefToLexemeName(SEMICOLON), typeDefToLexemeName(PARBEGIN),
        //        typeDefToLexemeName(tok->type));
        fprintf(file, "Syntax error in line %d: expected '%s' or '%s' , got '%s' \n",
                tok->lineNumber, typeDefToLexemeName(SEMICOLON), typeDefToLexemeName(PARBEGIN),
                tok->lexeme);
        errorRecovery(taskDefinitionsFollow, vec);
        break;
    }
}

void parseTaskDefinition(Vector *vec, FILE *file)
{
    Token *tok;

    // printf("Rule: TASK_DEFINITION -> task id begin DECLARATIONS { COMMANDS } end \n");
    fprintf(file, "Rule: TASK_DEFINITION -> task id begin DECLARATIONS { COMMANDS } end \n");

    tok = nextToken(vec, &fileIndex);

    switch (tok->type)
    {
    case TASK:
        match(ID, vec, file);
        match(BEGIN_SECTION, vec, file);

        parseDeclarations(vec, file);

        match(CURLY_BRACES_LEFT, vec, file);

        parseCommands(vec, file);

        match(CURLY_BRACES_RIGHT, vec, file);
        match(END_SECTION, vec, file);

        break;
    default:
        // printf("Syntax error in line %d: expected '%s', got '%s' \n",
        //        tok->lineNumber, typeDefToLexemeName(TASK),
        //        typeDefToLexemeName(tok->type));
        fprintf(file, "Syntax error in line %d: expected '%s', got '%s' \n",
                tok->lineNumber, typeDefToLexemeName(TASK),
                tok->lexeme);
        errorRecovery(taskDefinitionsFollow, vec);
        break;
    }
}

void parseDeclarations(Vector *vec, FILE *file)
{
    Token *tok;

    // printf("Rule: DECLARATIONS-> DECLARATION  |  DECLARATION; DECLARATIONS \n");
    fprintf(file, "Rule: DECLARATIONS-> DECLARATION  |  DECLARATION; DECLARATIONS \n");

    parseDeclaration(vec, file);

    tok = nextToken(vec, &fileIndex);

    switch (tok->type)
    {
    case SEMICOLON:
        tok = nextToken(vec, &fileIndex);
        switch (tok->type)
        {
        case INTEGER:
        case REAL:
            backToken(vec, &fileIndex);
            parseDeclarations(vec, file);
            break;
        default:
            // printf("Syntax error in line %d: expected '%s' or '%s', got '%s'\n",
            //        tok->lineNumber, typeDefToLexemeName(INTEGER), typeDefToLexemeName(REAL),
            //        typeDefToLexemeName(tok->type));
            fprintf(file, "Syntax error in line %d: expected '%s' or '%s', got '%s'\n",
                    tok->lineNumber, typeDefToLexemeName(INTEGER), typeDefToLexemeName(REAL),
                    tok->lexeme);
            errorRecovery(declarationsFollow, vec);
            break;
        }
        break;
    case CURLY_BRACES_LEFT:
    case ROUND_BRACKETS_RIGHT:
        backToken(vec, &fileIndex);
        break;
    default:
        // printf("Syntax error in line %d: expected '%s' or '%s' or '%s', got '%s' \n",
        //        tok->lineNumber, typeDefToLexemeName(SEMICOLON), typeDefToLexemeName(CURLY_BRACES_LEFT),
        //         typeDefToLexemeName(ROUND_BRACKETS_RIGHT),
        //        typeDefToLexemeName(tok->type));
        fprintf(file, "Syntax error in line %d: expected '%s' or '%s' or '%s', got '%s' \n",
                tok->lineNumber, typeDefToLexemeName(SEMICOLON), typeDefToLexemeName(CURLY_BRACES_LEFT),
                typeDefToLexemeName(ROUND_BRACKETS_RIGHT),
                tok->lexeme);
        errorRecovery(declarationsFollow, vec);
        break;
    }
}

void parseDeclaration(Vector *vec, FILE *file)
{
    Token *tok;

    // printf("Rule: DECLARATION -> integer  id   |  real id \n");
    fprintf(file, "Rule: DECLARATION -> integer  id   |  real id \n");

    tok = nextToken(vec, &fileIndex);
    switch (tok->type)
    {
    case INTEGER:
    case REAL:
        match(ID, vec, file);
        break;
    default:
        // printf("Syntax error in line %d: expected '%s' or '%s' , got '%s' \n",
        //        tok->lineNumber, typeDefToLexemeName(INTEGER), typeDefToLexemeName(REAL),
        //        typeDefToLexemeName(tok->type));
        fprintf(file, "Syntax error in line %d: expected '%s' or '%s' , got '%s' \n",
                tok->lineNumber, typeDefToLexemeName(INTEGER), typeDefToLexemeName(REAL),
                tok->lexeme);
        errorRecovery(declarationFollow, vec);
        break;
    }
}

void parseTaskList(Vector *vec, FILE *file)
{
    Token *tok;

    // printf("Rule: TASK_LIST -> task_id ||  TASK_LIST\n");
    fprintf(file, "Rule: TASK_LIST -> task_id ||  TASK_LIST\n");

    tok = nextToken(vec, &fileIndex);
    switch (tok->type)
    {
    case ID:
        tok = nextToken(vec, &fileIndex);
        switch (tok->type)
        {
        case TASK_PARALLEL:
            parseTaskList(vec, file);
            break;
        case PAREND:
            backToken(vec, &fileIndex);
            break;
        default:
            // printf("Syntax error in line %d: expected '%s' or '%s' , got '%s' \n",
            //        tok->lineNumber, typeDefToLexemeName(TASK_PARALLEL), typeDefToLexemeName(PAREND),
            //        typeDefToLexemeName(tok->type));
            fprintf(file, "Syntax error in line %d: expected '%s' or '%s' , got '%s' \n",
                    tok->lineNumber, typeDefToLexemeName(TASK_PARALLEL), typeDefToLexemeName(PAREND),
                    tok->lexeme);
            errorRecovery(declarationFollow, vec);
            break;
        }
        break;
    case PAREND:
        backToken(vec, &fileIndex);
        break;
    default:
        // printf("Syntax error in line %d: expected '%s' or '%s' , got '%s' \n",
        //        tok->lineNumber, typeDefToLexemeName(ID), typeDefToLexemeName(PAREND),
        //        typeDefToLexemeName(tok->type));
        fprintf(file, "Syntax error in line %d: expected '%s' or '%s' , got '%s' \n",
                tok->lineNumber, typeDefToLexemeName(ID), typeDefToLexemeName(PAREND),
                tok->lexeme);
        errorRecovery(declarationFollow, vec);
        break;
    }
}

void parseCommands(Vector *vec, FILE *file)
{
    Token *tok;

    // printf("Rule: COMMANDS -> COMMAND  | COMMAND; COMMANDS  \n");
    fprintf(file, "Rule: COMMANDS -> COMMAND  | COMMAND; COMMANDS  \n");

    parseCommand(vec, file);

    tok = nextToken(vec, &fileIndex);
    switch (tok->type)
    {
    case SEMICOLON:
        tok = nextToken(vec, &fileIndex);
        switch (tok->type)
        {
        case ID:
        case DO:
        case SEND:
        case ACCEPT:
        case BEGIN_SECTION:
            backToken(vec, &fileIndex);
            parseCommands(vec, file);
            break;
        default:
            // printf("Syntax error in line %d: expected '%s' or '%s' or '%s' or '%s' or '%s', got '%s' \n",
            //        tok->lineNumber, typeDefToLexemeName(ID), typeDefToLexemeName(DO), typeDefToLexemeName(SEND),
            //        typeDefToLexemeName(ACCEPT), typeDefToLexemeName(BEGIN_SECTION), typeDefToLexemeName(tok->type));
            fprintf(file, "Syntax error in line %d: expected '%s' or '%s' or '%s' or '%s' or '%s', got '%s' \n",
                    tok->lineNumber, typeDefToLexemeName(ID), typeDefToLexemeName(DO), typeDefToLexemeName(SEND),
                    typeDefToLexemeName(ACCEPT), typeDefToLexemeName(BEGIN_SECTION), tok->lexeme);
            errorRecovery(commandsFollow, vec);
            break;
        }
        break;
    case CURLY_BRACES_RIGHT:
    case UNTIL:
        backToken(vec, &fileIndex);
        break;
    default:
        // printf("Syntax error in line %d: expected '%s' or '%s' or '%s', got '%s' \n",
        //        tok->lineNumber, typeDefToLexemeName(SEMICOLON),
        //        typeDefToLexemeName(CURLY_BRACES_RIGHT), typeDefToLexemeName(UNTIL),
        //        typeDefToLexemeName(tok->type));
        fprintf(file, "Syntax error in line %d: expected '%s' or '%s' or '%s', got '%s' \n",
                tok->lineNumber, typeDefToLexemeName(SEMICOLON),
                typeDefToLexemeName(CURLY_BRACES_RIGHT), typeDefToLexemeName(UNTIL),
                tok->lexeme);
        errorRecovery(commandsFollow, vec);
        break;
    }
}
void parseCommand(Vector *vec, FILE *file)
{
    Token *tok;

    // printf("Rule: COMMAND -> id = EXPRESSION | do COMMANDS until CONDITION od | send task_id . signal_id (PARAM_LIST) | accept signal_id (DECLARATIONS) | begin DECLARATIONS { COMMANDS } end  \n");
    fprintf(file, "Rule: COMMAND -> id = EXPRESSION | do COMMANDS until CONDITION od | send task_id . signal_id (PARAM_LIST) | accept signal_id (DECLARATIONS) | begin DECLARATIONS { COMMANDS } end  \n");

    tok = nextToken(vec, &fileIndex);
    switch (tok->type)
    {
    case ID:
        // printf("Rule: id = EXPRESSION  \n");
        fprintf(file, "Rule: id = EXPRESSION  \n");
        match(ASSIGNMENT, vec, file);
        parseExpression(vec, file);
        break;
    case DO:
        // printf("Rule: do COMMANDS until CONDITION od \n");
        fprintf(file, "Rule: do COMMANDS until CONDITION od \n");

        parseCommands(vec, file);

        match(UNTIL, vec, file);

        parseCondition(vec, file);

        match(OD, vec, file);
        break;

    case SEND:
        // printf("Rule: end task_id . signal_id (PARAM_LIST)  \n");
        fprintf(file, "Rule: end task_id . signal_id (PARAM_LIST)  \n");
        match(ID, vec, file);
        match(TASK_PERIOD, vec, file);
        match(ID, vec, file);
        match(ROUND_BRACKETS_LEFT, vec, file);

        parseParamList(vec, file);

        match(ROUND_BRACKETS_RIGHT, vec, file);
        break;
    case ACCEPT:
        // printf("Rule: accept signal_id (DECLARATIONS)  \n");
        fprintf(file, "Rule: accept signal_id (DECLARATIONS)  \n");
        match(ID, vec, file);
        match(ROUND_BRACKETS_LEFT, vec, file);

        parseDeclarations(vec, file);

        match(ROUND_BRACKETS_RIGHT, vec, file);
        break;
    case BEGIN_SECTION:
        // printf("Rule: begin DECLARATIONS { COMMANDS } end \n");
        fprintf(file, "Rule: begin DECLARATIONS { COMMANDS } end \n");
        parseDeclarations(vec, file);

        match(CURLY_BRACES_LEFT, vec, file);

        parseCommands(vec, file);

        match(CURLY_BRACES_RIGHT, vec, file);
        match(END_SECTION, vec, file);
        break;
    case CURLY_BRACES_RIGHT:
        backToken(vec, &fileIndex);
        break;
    default:
        // printf("Syntax error in line %d: expected '%s' or '%s' or '%s' or '%s' or '%s', got '%s' \n",
        //        tok->lineNumber, typeDefToLexemeName(ID), typeDefToLexemeName(DO), typeDefToLexemeName(SEND),
        //        typeDefToLexemeName(ACCEPT), typeDefToLexemeName(BEGIN_SECTION), typeDefToLexemeName(tok->type));
        fprintf(file, "Syntax error in line %d: expected '%s' or '%s' or '%s' or '%s' or '%s', got '%s' \n",
                tok->lineNumber, typeDefToLexemeName(ID), typeDefToLexemeName(DO), typeDefToLexemeName(SEND),
                typeDefToLexemeName(ACCEPT), typeDefToLexemeName(BEGIN_SECTION), tok->lexeme);
        errorRecovery(commandFollow, vec);
        break;
    }
}

void parseExpression(Vector *vec, FILE *file)
{
    Token *tok;

    // printf("Rule: EXPRESSION \n");
    fprintf(file, "Rule: EXPRESSION \n");

    tok = nextToken(vec, &fileIndex);

    switch (tok->type)
    {

    case ID:
        tok = nextToken(vec, &fileIndex);
        switch (tok->type)
        {
        case BINARY_ADDITION:
        case BINARY_SUBTRACTION:
        case BINARY_MULTIPLICATION:
        case BINARY_DIVISION:
            parseExpression(vec, file);
            break;
        case DO:
        case SEND:
        case ACCEPT:
        case BEGIN_SECTION:
        case CURLY_BRACES_RIGHT:
        case ROUND_BRACKETS_RIGHT:
        case COMMA:
            backToken(vec, &fileIndex);
            break;
        default:
            // printf("Syntax error in line %d: expected '%s' or '%s' or '%s' or '%s', got '%s' \n",
            //        tok->lineNumber, typeDefToLexemeName(BINARY_ADDITION), typeDefToLexemeName(BINARY_SUBTRACTION),
            //        typeDefToLexemeName(BINARY_MULTIPLICATION), typeDefToLexemeName(BINARY_DIVISION),
            //        typeDefToLexemeName(tok->type));
            fprintf(file, "Syntax error in line %d: expected '%s' or '%s' or '%s' or '%s', got '%s' \n",
                   tok->lineNumber, typeDefToLexemeName(BINARY_ADDITION), typeDefToLexemeName(BINARY_SUBTRACTION),
                   typeDefToLexemeName(BINARY_MULTIPLICATION), typeDefToLexemeName(BINARY_DIVISION),
                   tok->lexeme);
            errorRecovery(expressionFollow, vec);
            break;
        }
        break;
    case INTEGER_NUMBER:
    case REAL_NUMBER:
        break;
    default:
        // printf("Syntax error in line %d: expected '%s' or '%s' or '%s', got '%s' \n",
        //        tok->lineNumber, typeDefToLexemeName(ID), typeDefToLexemeName(INTEGER_NUMBER), typeDefToLexemeName(REAL_NUMBER),
        //        typeDefToLexemeName(tok->type));
        fprintf(file, "Syntax error in line %d: expected '%s' or '%s' or '%s', got '%s' \n",
               tok->lineNumber, typeDefToLexemeName(ID), typeDefToLexemeName(INTEGER_NUMBER), typeDefToLexemeName(REAL_NUMBER),
               tok->lexeme);
        errorRecovery(expressionFollow, vec);
        break;
    }
}

void parseParamList(Vector *vec, FILE* file)
{
    Token *tok;

    // printf("Rule: PARAM_LIST -> EXPRESSION  |  EXPRESSION, PARAM_LIST  \n");
    fprintf(file, "Rule: PARAM_LIST -> EXPRESSION  |  EXPRESSION, PARAM_LIST  \n");

    parseExpression(vec, file);

    tok = nextToken(vec, &fileIndex);

    switch (tok->type)
    {
    case COMMA:
        parseParamList(vec, file);
        break;
    case ROUND_BRACKETS_RIGHT:
        backToken(vec, &fileIndex);
        break;
    default:
        // printf("Syntax error in line %d: expected '%s' or '%s', got '%s' \n",
        //        tok->lineNumber, typeDefToLexemeName(COMMA), typeDefToLexemeName(ROUND_BRACKETS_RIGHT),
        //        typeDefToLexemeName(tok->type));
        fprintf(file,"Syntax error in line %d: expected '%s' or '%s', got '%s' \n",
               tok->lineNumber, typeDefToLexemeName(COMMA), typeDefToLexemeName(ROUND_BRACKETS_RIGHT),
               tok->lexeme);
        errorRecovery(conditionFollow, vec);
        break;
    }
}

void parseCondition(Vector *vec, FILE* file)
{
    Token *tok;

    // printf("Rule: CONDITION -> (id  rel_op  id)  \n");
    fprintf(file, "Rule: CONDITION -> (id  rel_op  id)  \n");

    match(ROUND_BRACKETS_LEFT, vec, file);
    match(ID, vec, file);

    tok = nextToken(vec, &fileIndex);

    switch (tok->type)
    {
    case EQUAL:
    case NOT_EQUAL:
    case GREATER:
    case LESSER:
    case LESSER_EQUAL:
    case GREATER_EQUAL:
        break;
    default:
        // printf("Syntax error in line %d: expected '%s' or '%s' or '%s' or '%s' or '%s' or '%s', got '%s' \n",
        //        tok->lineNumber, typeDefToLexemeName(EQUAL), typeDefToLexemeName(NOT_EQUAL),
        //        typeDefToLexemeName(GREATER), typeDefToLexemeName(LESSER),
        //        typeDefToLexemeName(LESSER_EQUAL), typeDefToLexemeName(GREATER_EQUAL),
        //        typeDefToLexemeName(tok->type));
        fprintf(file, "Syntax error in line %d: expected '%s' or '%s' or '%s' or '%s' or '%s' or '%s', got '%s' \n",
               tok->lineNumber, typeDefToLexemeName(EQUAL), typeDefToLexemeName(NOT_EQUAL),
               typeDefToLexemeName(GREATER), typeDefToLexemeName(LESSER),
               typeDefToLexemeName(LESSER_EQUAL), typeDefToLexemeName(GREATER_EQUAL),
               tok->lexeme);
        errorRecovery(conditionFollow, vec);
        break;
    }

    match(ID, vec, file);
    match(ROUND_BRACKETS_RIGHT, vec, file);
}