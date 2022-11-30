%option yylineno
%{
/* prologue */

	#include <stdlib.h>
	#include "parser.tab.h"
	#include "ast.h" 

	
%}

stdio           (std::)
delim		    [ \t]
ws 			    {delim}+
digit 		    [0-9]
int_number      [0]+|-?[1-9][0-9]*
float_number 	-?{digit}+(\.{digit}+)?(E[+-]?{digit}+)?
letter 		    [A-Za-z]
id 			    {letter}({letter}|{digit})*
bool_v		    true|false
string_v	    \"[^\"]*\"

%x 							comment
%x 							commentsl
%x 							library
%x 							namespacestd

%%

"/*" 						BEGIN(comment);
<comment>[^*\n]* 			/* eat anything that's not a '*' */
<comment>"*"+[^*/\n]* 		/* eat up '*'s not followed by '/'s */
<comment>\n 				/* possible new lines */
<comment>"*"+"/" 			BEGIN(INITIAL);
"//" 						BEGIN(commentsl);
<commentsl>[^\n]* 			/* eat anything that's not a new line */
<commentsl>\n 				BEGIN(INITIAL);
"#" 						BEGIN(library);
<library>[^\n]* 			/* eat anything that's not a new line */
<library>\n 				BEGIN(INITIAL);
"using namespace std;"		BEGIN(namespacestd);
<namespacestd>[^\n]* 		/* eat anything that's not a new line */
<namespacestd>\n 			BEGIN(INITIAL);


"if" 		{printf("KEYWORD 'IF' found at line %d.\n",yylineno);return(IF);}
"else" 		{printf("KEYWORD 'ELSE' found at line %d.\n",yylineno);return(ELSE);}
"float" 	{printf("KEYWORD 'FLOAT' found at line %d.\n",yylineno);return(FLOAT) ;}
"int" 		{printf("KEYWORD 'INT' found at line %d.\n",yylineno);return(INT);}
"bool"		{printf("KEYWORD 'BOOL' found at line %d.\n",yylineno);return(BOOL);}
"string"	{printf("KEYWORD 'STRING' found at line %d.\n",yylineno);return(STRING);}
"return"	{printf("KEYWORD 'RETURN' found at line %d.\n",yylineno);return(RETURN);}
"cout"		{printf("KEYWORD 'COUT' found at line %d.\n",yylineno);return(COUT);}
"cin"		{printf("KEYWORD 'CIN' found at line %d.\n",yylineno);return(CIN);}
"for"		{printf("KEYWORD 'FOR' found at line %d.\n",yylineno);return(FOR);}
"<<"		{printf("OPERATOR '<<' found at line %d.\n",yylineno);return(LSHIFT);}
">>"		{printf("OPERATOR '>>' found at line %d.\n",yylineno);return(RSHIFT);}
"<=" 		{printf("OPERATOR '<=' found at line %d.\n",yylineno);yylval.string=strdup(yytext);return(LE);}
"==" 		{printf("OPERATOR '==' found at line %d.\n",yylineno);yylval.string=strdup(yytext);return(EEQ);}
">=" 		{printf("OPERATOR '>=' found at line %d.\n",yylineno);yylval.string=strdup(yytext);return(GE);}
"!=" 		{printf("OPERATOR '!=' found at line %d.\n",yylineno);yylval.string=strdup(yytext);return(NE);}
"<" 		{printf("OPERATOR '<' found at line %d.\n",yylineno);yylval.string=strdup(yytext);return(LT);}
"=" 		{printf("OPERATOR '=' found at line %d.\n",yylineno);yylval.string=strdup(yytext);return(EQ);}
">" 		{printf("OPERATOR '>' found at line %d.\n",yylineno);yylval.string=strdup(yytext);return(GT);}
"&&" 		{printf("OPERATOR 'AND' found at line %d.\n",yylineno);yylval.string=strdup(yytext);return(AND);}
"||" 		{printf("OPERATOR 'OR' found at line %d.\n",yylineno);yylval.string=strdup(yytext);return(OR);}
"(" 		{yylval.string=strdup(yytext);return(LPAR);}
")" 		{yylval.string=strdup(yytext);return(RPAR);}
"{" 		{yylval.string=strdup(yytext);return(LBRACE);}
"}" 		{yylval.string=strdup(yytext);return(RBRACE);}
":" 		{yylval.string=strdup(yytext);return(COLON);}
";" 		{yylval.string=strdup(yytext);return(SEMICOLON);}
"," 		{yylval.string=strdup(yytext);return(COMMA);}
"."			{yylval.string=strdup(yytext);return(DOT);}
"+" 		{printf("OPERATOR '+' found at line %d.\n",yylineno);yylval.string=strdup(yytext);return(ADD);}
"-" 		{printf("OPERATOR '-' found at line %d.\n",yylineno);yylval.string=strdup(yytext);return(SUB);}
"*" 		{printf("OPERATOR '*' found at line %d.\n",yylineno);yylval.string=strdup(yytext);return(MUL);}
"/" 		{printf("OPERATOR '/' found at line %d.\n",yylineno);yylval.string=strdup(yytext);return(DIV);}
"class" 	{printf("KEYWORD 'CLASS' found at line %d.\n",yylineno);return(CLASS);}
"public"	{printf("KEYWORD 'PUBLIC' found at line %d.\n",yylineno);return(PUBLIC);}
"private"	{printf("KEYWORD 'PRIVATE' found at line %d.\n",yylineno);return(PRIVATE);}
"main"		{printf("KEYWORD 'MAIN' found at line %d.\n",yylineno);yylval.string=strdup(yytext);return(MAIN);}
"\n"        {/* no action and no return */}


{ws} 		    {/* no action and no return */}
{stdio}		    {/* no action and no return */}
{int_number} 	{yylval.string=strdup(yytext); printf("INT NUMBER '%s' found at line %d.\n",yylval.string,yylineno); 	return(INT_NUMBER) ;}
{float_number} 	{yylval.string=strdup(yytext); printf("FLOAT NUMBER '%s' found at line %d.\n",yylval.string,yylineno); return(FLOAT_NUMBER) ;}
{bool_v}	    {yylval.string=strdup(yytext); printf("BOOL VALUE '%s' found at line %d.\n",yylval.string,yylineno); 	return(BOOL_V) ;}
{id} 		    {yylval.string=strdup(yytext); printf("ID '%s' found at line %d.\n",yylval.string,yylineno); 			return(ID) ;}
{string_v}	    {yylval.string=strdup(yytext); printf("STRING '%s' found at line %d.\n",yylval.string,yylineno); 		return(STRING_V) ;}

.           {printf("Unknown character! \n"); return(UNKNOWN);}

%%
