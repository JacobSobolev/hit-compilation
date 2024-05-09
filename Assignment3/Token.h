#ifndef TOKEN
#define TOKEN

typedef struct {
  int type;
  char *lexeme;
  int lineNumber;
} Token;

char* DefToLexemeStrMap[]={"Parbegin", "Parend",\
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
              "End Of File", "Signal"};

char* DefToLexemeNameMap[]={"parbegin", "parend",\
              "task",\
              "real", "integer",\
              "=","do", "until", "od",\
              "send", "accept",\
              "begin","end",\
              "+", "-","*", "/",\
              "==", "!=", ">", "<", "<=", ">=",\
              ",",";", "(", ")","{", "}","||",".",\
              "id",\
              "integer number", "real number",\
              "EOF", "signal"};

char *typeDefToLexemeStr(int i);
char *typeDefToLexemeName(int i);
void PrintToken(Token *, FILE *);

#endif
