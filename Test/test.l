%{
int line=1;
%}
%name lex
%%
\n   {line++;  printf("\n%d:",line);}
.       ECHO;
%%
void main(int argc, char* argv[])
{
	yyin=fopen(argv[1],"r");
	printf("1:");
	yylex();
}