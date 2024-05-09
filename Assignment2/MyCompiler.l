%{
#include "lexemesDefinitions.h"
#include "Token.c"
#include "Vector.c"
#include "lexicalUtils.c"
#include "parserUtils.c"


// int lineNumber = 1;
// int fileIndex = 0;
int endOfFile = 0;
Vector vec;

void printHelp();

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
{parbegin}              {createAndStoreToken(&vec, PARBEGIN, yytext, lineNumber); return 1;}
{parend}                {createAndStoreToken(&vec, PAREND, yytext, lineNumber); return 1;}


{task}                  {createAndStoreToken(&vec, TASK, yytext, lineNumber); return 1;}

{real}                  {createAndStoreToken(&vec, REAL, yytext, lineNumber); return 1;}
{integer}               {createAndStoreToken(&vec, INTEGER, yytext, lineNumber); return 1;}

{assignment}            {createAndStoreToken(&vec, ASSIGNMENT, yytext, lineNumber); return 1;}
{do}                    {createAndStoreToken(&vec, DO, yytext, lineNumber); return 1;}
{until}                 {createAndStoreToken(&vec, UNTIL, yytext, lineNumber); return 1;}
{od}                    {createAndStoreToken(&vec, OD, yytext, lineNumber); return 1;}

{send}                  {createAndStoreToken(&vec, SEND, yytext, lineNumber); return 1;}
{accept}                {createAndStoreToken(&vec, ACCEPT, yytext, lineNumber); return 1;}

{beginSection}          {createAndStoreToken(&vec, BEGIN_SECTION, yytext, lineNumber); return 1;}
{endSection}            {createAndStoreToken(&vec, END_SECTION, yytext, lineNumber); return 1;}

{BinaryAddition}        {createAndStoreToken(&vec, BINARY_ADDITION, yytext, lineNumber); return 1;}
{BinarySubtraction}     {createAndStoreToken(&vec, BINARY_SUBTRACTION, yytext, lineNumber); return 1;}
{BinaryMultiplication}  {createAndStoreToken(&vec, BINARY_MULTIPLICATION, yytext, lineNumber); return 1;}
{BinaryDivision}        {createAndStoreToken(&vec, BINARY_DIVISION, yytext, lineNumber); return 1;}

{equal}                 {createAndStoreToken(&vec, EQUAL, yytext, lineNumber); return 1;}
{notEqual}              {createAndStoreToken(&vec, NOT_EQUAL, yytext, lineNumber); return 1;}
{greater}               {createAndStoreToken(&vec, GREATER, yytext, lineNumber); return 1;}
{lesser}                {createAndStoreToken(&vec, LESSER, yytext, lineNumber); return 1;}
{lesserEqual}           {createAndStoreToken(&vec, LESSER_EQUAL, yytext, lineNumber); return 1;}
{greaterEqual}          {createAndStoreToken(&vec, GREATER_EQUAL, yytext, lineNumber); return 1;}

{comma}                 {createAndStoreToken(&vec, COMMA, yytext, lineNumber); return 1;}
{semicolon}             {createAndStoreToken(&vec, SEMICOLON, yytext, lineNumber); return 1;}
{roundBracketsLeft}     {createAndStoreToken(&vec, ROUND_BRACKETS_LEFT, yytext, lineNumber); return 1;}
{roundBracketsRight}    {createAndStoreToken(&vec, ROUND_BRACKETS_RIGHT, yytext, lineNumber); return 1;}
{curlyBracesLeft}       {createAndStoreToken(&vec, CURLY_BRACES_LEFT, yytext, lineNumber); return 1;}
{curlyBracesRight}      {createAndStoreToken(&vec, CURLY_BRACES_RIGHT, yytext, lineNumber); return 1;}

{taskParallel}          {createAndStoreToken(&vec, TASK_PARALLEL, yytext, lineNumber); return 1;}
{period}                {createAndStoreToken(&vec, TASK_PERIOD, yytext, lineNumber); return 1;}

{id}                    {createAndStoreToken(&vec, ID, yytext, lineNumber); return 1;}

{integerNumber}         {createAndStoreToken(&vec, INTEGER_NUMBER, yytext, lineNumber); return 1;}
{realNumber}            {createAndStoreToken(&vec, REAL_NUMBER, yytext, lineNumber); return 1;}



{newLine}               {lineNumber++;}
<<EOF>>                 {createAndStoreToken(&vec, EOF_, yytext, lineNumber); endOfFile = 1; return 1;}
{space}    
{carriageReturn}
{tab}
{idNotLegal}            {PrintError(yytext, lineNumber, yyout);}
.                       {PrintError(yytext, lineNumber, yyout);}

%%

void main(int argc, char *argv[])
{
    // int i = 0;
    

    if (argc < 4 ){
        printHelp();
    }
    else{
        if (strcmp(argv[1], "-l") == 0){
            yyin = fopen(argv[2], "r");     
            if (yyin != NULL){
                CreateVector(&vec);
                yyout = fopen(argv[3], "w");
            
                while(!endOfFile){
                    PrintToken(nextToken(&vec, &fileIndex), yyout);
                    
                }
                DeleteVector(&vec);
            }
            else{
                printHelp();
            }
        }
        else if (strcmp(argv[1], "-p") == 0){
            yyin = fopen(argv[2], "r");     
            if (yyin != NULL){
                CreateVector(&vec);
                yyout = fopen(argv[3], "w");

                parseProgram(&vec, yyout);
                match(EOF_, &vec, yyout);

                DeleteVector(&vec);
            }
            else{
                printHelp();
            }
        }
        else{
            printHelp();
        }
    }
	
}

void printHelp()
{
    printf("this is a compiler for Grammer G\n");
    printf("1 argument pass the functionality -l for lexical -p for parser\n");
    printf("2 argument pass the input file to read from\n");
    printf("3 argument pass the output file to write to\n");
}