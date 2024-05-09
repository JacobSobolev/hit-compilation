ECHO OFF
lex.yy.exe -l C:\temp\test1.txt c:\temp\test1__lex.txt
lex.yy.exe -l C:\temp\test2.txt c:\temp\test2__lex.txt
lex.yy.exe -p C:\temp\test1.txt c:\temp\test1__syntactic.txt
lex.yy.exe -p C:\temp\test2.txt c:\temp\test2__syntactic.txt
ECHO please check your output files