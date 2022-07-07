%{
    #include<stdio.h>
%}

%%
if|else|for|while|do|switch|int|float {printf("%s is a reserved word\n",yytext);}
[[a-zA-Z_]|[a-zA-Z0-9]*]  {printf("%s is a identifier\n",yytext);}
[0-9]* {printf("%s is a number\n",yytext);}
[*/+%] {printf("%s is a operator\n",yytext);}
%%

void main()
{ 
    yylex();
}
