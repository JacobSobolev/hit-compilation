%{
    
#include "Vector.c"
#include "TypeDefinitions.h"
#include "Token.h"

int lineNumber = 1;
int fileIndex = 0;
int endOfFile = 0;
Vector vec;

Token* nextToken();
Token* backToken();
void createAndStoreToken(int, char*, int);
void PrintError(char*);
char* GetLexemeStr(int);

%}
%name lex

//program
parbegin                "parbegin"
parend                  "parend"


//tasks
task                    "task"

//declarations
real                    "real"
integer                 "integer"

//commands
assignment              "="
do                      "do"
until                   "until"
od                      "od"

send                    "send"
accept                  "accept"

//several sections (declarations, command)
beginSection            "begin"
endSection              "end"

//binary_ar_op
BinaryAddition          "+"
BinarySubtraction       "-"
BinaryMultiplication    "*"
BinaryDivision          "/"

//rel_op
equal                   "=="
notEqual                "!="
greater                 ">"
lesser                  "<"
lesserEqual             "<="
greaterEqual            ">="


//signs
comma                   ","
semicolon		        ";"
roundBracketsLeft       "("
roundBracketsRight      ")"
curlyBracesLeft	        "{"
curlyBracesRight	    "}"


space                   " "
tab                     "\t"
newLine                 "\n"
carriageReturn          "\r"

period                  "."
taskParallel            "||"


//helpers for regular expresions
digit                   [0-9]
letterLowerCase         [a-z]
letterUpperCase         [A-Z]
minus                   "-"

//regular expresions

id			            {letterLowerCase}({letterLowerCase}|{digit})*
idNotLegal              (({letterUpperCase})+|{digit}|{letterLowerCase})*

integerNumber		    ({digit})+|{minus}({digit})+
realNumber	            ({digit})+{period}({digit})+|{minus}({digit})+{period}({digit})+

%x comment1 comment2

%%
{parbegin}              {createAndStoreToken(PARBEGIN, yytext, lineNumber); return 1;}
{parend}                {createAndStoreToken(PAREND, yytext, lineNumber); return 1;}


{task}                  {createAndStoreToken(TASK, yytext, lineNumber); return 1;}

{real}                  {createAndStoreToken(REAL, yytext, lineNumber); return 1;}
{integer}               {createAndStoreToken(INTEGER, yytext, lineNumber); return 1;}

{assignment}            {createAndStoreToken(ASSIGNMENT, yytext, lineNumber); return 1;}
{do}                    {createAndStoreToken(DO, yytext, lineNumber); return 1;}
{until}                 {createAndStoreToken(UNTIL, yytext, lineNumber); return 1;}
{od}                    {createAndStoreToken(OD, yytext, lineNumber); return 1;}

{send}                  {createAndStoreToken(SEND, yytext, lineNumber); return 1;}
{accept}                {createAndStoreToken(ACCEPT, yytext, lineNumber); return 1;}

{beginSection}          {createAndStoreToken(BEGIN_SECTION, yytext, lineNumber); return 1;}
{endSection}            {createAndStoreToken(END_SECTION, yytext, lineNumber); return 1;}

{BinaryAddition}        {createAndStoreToken(BINARY_ADDITION, yytext, lineNumber); return 1;}
{BinarySubtraction}     {createAndStoreToken(BINARY_SUBTRACTION, yytext, lineNumber); return 1;}
{BinaryMultiplication}  {createAndStoreToken(BINARY_MULTIPLICATION, yytext, lineNumber); return 1;}
{BinaryDivision}        {createAndStoreToken(BINARY_DIVISION, yytext, lineNumber); return 1;}

{equal}                 {createAndStoreToken(EQUAL, yytext, lineNumber); return 1;}
{notEqual}              {createAndStoreToken(NOT_EQUAL, yytext, lineNumber); return 1;}
{greater}               {createAndStoreToken(GREATER, yytext, lineNumber); return 1;}
{lesser}                {createAndStoreToken(LESSER, yytext, lineNumber); return 1;}
{lesserEqual}           {createAndStoreToken(LESSER_EQUAL, yytext, lineNumber); return 1;}
{greaterEqual}          {createAndStoreToken(GREATER_EQUAL, yytext, lineNumber); return 1;}

{comma}                 {createAndStoreToken(COMMA, yytext, lineNumber); return 1;}
{semicolon}             {createAndStoreToken(SEMICOLON, yytext, lineNumber); return 1;}
{roundBracketsLeft}     {createAndStoreToken(ROUND_BRACKETS_LEFT, yytext, lineNumber); return 1;}
{roundBracketsRight}    {createAndStoreToken(ROUND_BRACKETS_RIGHT, yytext, lineNumber); return 1;}
{curlyBracesLeft}       {createAndStoreToken(CURLY_BRACES_LEFT, yytext, lineNumber); return 1;}
{curlyBracesRight}      {createAndStoreToken(CURLY_BRACES_RIGHT, yytext, lineNumber); return 1;}

{taskParallel}          {createAndStoreToken(TASK_PARALLEL, yytext, lineNumber); return 1;}
{period}                {createAndStoreToken(TASK_PERIOD, yytext, lineNumber); return 1;}

{id}                    {createAndStoreToken(ID, yytext, lineNumber); return 1;}

{integerNumber}         {createAndStoreToken(INTEGER_NUMBER, yytext, lineNumber); return 1;}
{realNumber}            {createAndStoreToken(REAL_NUMBER, yytext, lineNumber); return 1;}



{newLine}               {lineNumber++;}
<<EOF>>                 {endOfFile = 1; return 0;}
{space}    
{carriageReturn}
{tab}
{idNotLegal}            {PrintError(yytext);}
.                       {PrintError(yytext);}

%%

void main(int argc, char *argv[])
{
    if (argc < 3 ){
        printf("this is a compiler\n");
        printf("1 argument pass the input file to read from\n");
        printf("2 argument pass the output file to write to\n");
    }
    else{
        
        yyin = fopen(argv[1], "r");     
        if (yyin != NULL){
            CreateVector(&vec);
            yyout = fopen(argv[2], "w");
        
            while(!endOfFile){
                PrintToken(nextToken());
                
            }
        }
        else{
            printf("the input file doens't exsists\n\n");
            printf("1 argument pass the input file to read from\n");
            printf("2 argument pass the output file to write to\n");
        }
        
    }
    
}

void createAndStoreToken(int type, char* lexeme, int lineNumber)
{	
    Token* tok = (Token*)malloc(sizeof(Token));
    tok->lineNumber = lineNumber;
    tok->type = type;
    tok->lexeme = lexeme;
    TokenAdd(&vec, tok);
	free(tok);
}

Token* nextToken()
{
   Token** tok = (Token**)malloc(sizeof(Token*));
   if(fileIndex == vec.index)
   {
        if (yylex())
        {
            *tok = &vec.tokens[fileIndex++];
        }
		else return NULL;
   }
   else
   {
        *tok = &vec.tokens[fileIndex++];
   }
   return *tok;
}

Token* backToken()
{
    Token** tok = (Token**)malloc(sizeof(Token*));
    if(fileIndex >= 2){
        *tok = &vec.tokens[(--fileIndex) - 1];
    }

    return *tok;
}

char* GetLexemeStr(int i){
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
                "Integer Number", "Real Number"};
	return lexemeMap[i];
}

void PrintToken(Token* t){
    if (t != NULL){
        fprintf(yyout, "Token from type '%s' was found at line: %d, lexeme: '%s'.\n", GetLexemeStr(t->type), t->lineNumber, t->lexeme);
    }
}


void PrintError(char* lexeme){
    fprintf(yyout, "The character '%s' at line: %d does not begin any legal token in the language.\n", lexeme, lineNumber);
}