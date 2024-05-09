ECHO OFF
lex.yy.exe InputFiles\lexInputOK.txt sometest1.txt
lex.yy.exe InputFiles\lexInputError.txt sometest2.txt
ECHO please check your output files