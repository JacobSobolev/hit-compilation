%{

#include "lexemesDefinitions.h"
#include "Token.c"
#include "Vector.c"
#include "lexicalUtils.c"
#include "parserUtils.c"
#include "StackScope.c"

// int lineNumber = 1;
// int fileIndex = 0;

int endOfFile = 0;
Vector vec;
StackScope stack;

FILE *yyoutlex;
FILE *yyoutsyn;
FILE *yyoutsem;


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


%%
{parbegin}              {PrintToken(createAndStoreToken(&vec, PARBEGIN, yytext, lineNumber), yyoutlex); return 1;}
{parend}                {PrintToken(createAndStoreToken(&vec, PAREND, yytext, lineNumber), yyoutlex); return 1;}


{task}                  {PrintToken(createAndStoreToken(&vec, TASK, yytext, lineNumber), yyoutlex); return 1;}

{real}                  {PrintToken(createAndStoreToken(&vec, REAL, yytext, lineNumber), yyoutlex); return 1;}
{integer}               {PrintToken(createAndStoreToken(&vec, INTEGER, yytext, lineNumber), yyoutlex); return 1;}

{assignment}            {PrintToken(createAndStoreToken(&vec, ASSIGNMENT, yytext, lineNumber), yyoutlex); return 1;}
{do}                    {PrintToken(createAndStoreToken(&vec, DO, yytext, lineNumber), yyoutlex); return 1;}
{until}                 {PrintToken(createAndStoreToken(&vec, UNTIL, yytext, lineNumber), yyoutlex); return 1;}
{od}                    {PrintToken(createAndStoreToken(&vec, OD, yytext, lineNumber), yyoutlex); return 1;}

{send}                  {PrintToken(createAndStoreToken(&vec, SEND, yytext, lineNumber), yyoutlex); return 1;}
{accept}                {PrintToken(createAndStoreToken(&vec, ACCEPT, yytext, lineNumber), yyoutlex); return 1;}

{beginSection}          {PrintToken(createAndStoreToken(&vec, BEGIN_SECTION, yytext, lineNumber), yyoutlex); return 1;}
{endSection}            {PrintToken(createAndStoreToken(&vec, END_SECTION, yytext, lineNumber), yyoutlex); return 1;}

{BinaryAddition}        {PrintToken(createAndStoreToken(&vec, BINARY_ADDITION, yytext, lineNumber), yyoutlex); return 1;}
{BinarySubtraction}     {PrintToken(createAndStoreToken(&vec, BINARY_SUBTRACTION, yytext, lineNumber), yyoutlex); return 1;}
{BinaryMultiplication}  {PrintToken(createAndStoreToken(&vec, BINARY_MULTIPLICATION, yytext, lineNumber), yyoutlex); return 1;}
{BinaryDivision}        {PrintToken(createAndStoreToken(&vec, BINARY_DIVISION, yytext, lineNumber), yyoutlex); return 1;}

{equal}                 {PrintToken(createAndStoreToken(&vec, EQUAL, yytext, lineNumber), yyoutlex); return 1;}
{notEqual}              {PrintToken(createAndStoreToken(&vec, NOT_EQUAL, yytext, lineNumber), yyoutlex); return 1;}
{greater}               {PrintToken(createAndStoreToken(&vec, GREATER, yytext, lineNumber), yyoutlex); return 1;}
{lesser}                {PrintToken(createAndStoreToken(&vec, LESSER, yytext, lineNumber), yyoutlex); return 1;}
{lesserEqual}           {PrintToken(createAndStoreToken(&vec, LESSER_EQUAL, yytext, lineNumber), yyoutlex); return 1;}
{greaterEqual}          {PrintToken(createAndStoreToken(&vec, GREATER_EQUAL, yytext, lineNumber), yyoutlex); return 1;}

{comma}                 {PrintToken(createAndStoreToken(&vec, COMMA, yytext, lineNumber), yyoutlex); return 1;}
{semicolon}             {PrintToken(createAndStoreToken(&vec, SEMICOLON, yytext, lineNumber), yyoutlex); return 1;}
{roundBracketsLeft}     {PrintToken(createAndStoreToken(&vec, ROUND_BRACKETS_LEFT, yytext, lineNumber), yyoutlex); return 1;}
{roundBracketsRight}    {PrintToken(createAndStoreToken(&vec, ROUND_BRACKETS_RIGHT, yytext, lineNumber), yyoutlex); return 1;}
{curlyBracesLeft}       {PrintToken(createAndStoreToken(&vec, CURLY_BRACES_LEFT, yytext, lineNumber), yyoutlex); return 1;}
{curlyBracesRight}      {PrintToken(createAndStoreToken(&vec, CURLY_BRACES_RIGHT, yytext, lineNumber), yyoutlex); return 1;}

{taskParallel}          {PrintToken(createAndStoreToken(&vec, TASK_PARALLEL, yytext, lineNumber), yyoutlex); return 1;}
{period}                {PrintToken(createAndStoreToken(&vec, TASK_PERIOD, yytext, lineNumber), yyoutlex); return 1;}

{integerNumber}         {PrintToken(createAndStoreToken(&vec, INTEGER_NUMBER, yytext, lineNumber), yyoutlex); return 1;}
{realNumber}            {PrintToken(createAndStoreToken(&vec, REAL_NUMBER, yytext, lineNumber), yyoutlex); return 1;}

{id}                    {PrintToken(createAndStoreToken(&vec, ID, yytext, lineNumber), yyoutlex); return 1;}




{newLine}               {lineNumber++;}
<<EOF>>                 {PrintToken(createAndStoreToken(&vec, EOF_, yytext, lineNumber), yyoutlex); endOfFile = 1; return 1;}
{space}
{carriageReturn}
{tab}
{idNotLegal}            {PrintLexError(yytext, lineNumber, yyoutlex);}
.                       {PrintLexError(yytext, lineNumber, yyoutlex);}

%%

int main(int argc, char *argv[])
{
    int testNumber = 1;

    const char* inputFileTest1 = "c:/temp/test1.txt";
    const char* inputFileTest2 = "c:/temp/test2.txt";

    const char* outputFileLexTest1 = "c:/temp/test1__lex.txt";
    const char* outputFileSynTest1 = "c:/temp/test1__syntactic.txt";
    const char* outputFileSemTest1 = "c:/temp/test1__semantic.txt";

    const char* outputFileLexTest2 = "c:/temp/test2__lex.txt";
    const char* outputFileSynTest2 = "c:/temp/test2__syntactic.txt";
    const char* outputFileSemTest2 = "c:/temp/test2__semantic.txt";

    printf("Custom compiler:\n\n");
    printf("Choose number of test to run:\n");
    printf("Press 1 or 2:\n");

    scanf("%d", &testNumber);

    if (testNumber != 1 && testNumber != 2){
      printf("Wrong Test Number, Choose 1 or 2\n");
      return 0;
    }

    if (testNumber == 1){
      yyin = fopen(inputFileTest1, "r");
    } else {
      yyin = fopen(inputFileTest2, "r");
    }

    if (yyin == NULL){
      printf("the input file test%d doesn't exsists in c:/temp", testNumber);
      return 0;
    }

    if (testNumber == 1){
      yyoutlex = fopen(outputFileLexTest1, "w");
      yyoutsyn = fopen(outputFileSynTest1, "w");
      yyoutsem = fopen(outputFileSemTest1, "w");
    } else {
      yyoutlex = fopen(outputFileLexTest2, "w");
      yyoutsyn = fopen(outputFileSynTest2, "w");
      yyoutsem = fopen(outputFileSemTest2, "w");
    }

    CreateVector(&vec);
    createStackScope(&stack);

    parseProgram(&vec, &stack, yyoutsyn, yyoutsem);
    match(EOF_, &vec, yyoutsyn);
    deleteStackScope(&stack);
    DeleteVector(&vec);
    fclose(yyin);
    fclose(yyoutlex);
    fclose(yyoutsyn);
    fclose(yyoutsem);
    printf("Done runing test %d, look for output in c:/temp", testNumber);

    return 1;

}
