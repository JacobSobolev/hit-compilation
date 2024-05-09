ECHO OFF
call "C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\vcvarsall.bat"
flex++.exe MyCompiler.l
cl lex.yy.c