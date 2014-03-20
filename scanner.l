%{
    
#include "tokens.h"
#include "hash.h"

int line_number = 1;
int running = 1;

%}

	/* Regular Definitions */
digit [0-9]
letter [a-zA-Z]
letter_ [a-zA-Z_]

	/* Special Characters: , ; : ( ) [ ] { } + - * / < > = ! & $    (this definition needs some tests...)*/
specialchar [,;:\(\)\[\]\{\}+\-*\/<>=!&$]


%x COMMENT

%%
	/* White Spaces */
\n              { ++line_number; }
[ \t]           { }

	/* Keywords */
word	{ return KW_WORD; }
bool	{ return KW_BOOL; }
byte	{ return KW_BYTE; }
if	    { return KW_IF; }
then	{ return KW_THEN; }
else	{ return KW_ELSE; }
loop	{ return KW_LOOP; }
input	{ return KW_INPUT; }
output	{ return KW_OUTPUT; }
return	{ return KW_RETURN; }

	/* Special Characters */
{specialchar}	{ return yytext[0]; }

	/*  Operators    */
"<="    { return OPERATOR_LE; }
">="    { return OPERATOR_GE; }
"=="    { return OPERATOR_EQ; }
"!="    { return OPERATOR_NE; }
"&&"    { return OPERATOR_AND; }
"||"    { return OPERATOR_OR; }

	/* Literals */
{digit}+	{ hashInsert(yytext, LIT_INTEGER); return LIT_INTEGER; }
false	    { return LIT_FALSE; }
true	    { return LIT_TRUE; }
\'.\'	    { hashInsert(yytext, LIT_CHAR); return LIT_CHAR; }
\".*\"	    { hashInsert(yytext, LIT_STRING); return LIT_STRING; }

	/* Identifier */
({letter_}|{digit})*{letter_}({letter_}|{digit})*	{ hashInsert(yytext, TK_IDENTIFIER); return TK_IDENTIFIER; }


"/*"            { BEGIN(COMMENT); }

	/*This must be the last INITIAL rule!*/
.               { return TOKEN_ERROR; }

<COMMENT>\n     { ++line_number; }
<COMMENT>"*/"   { BEGIN(INITIAL); }
<COMMENT>.
"//.* 		{}

%%

int getLineNumber (void)
{
	return line_number;
}

void initMe()
{
    hashInit();
}

int yywrap()
{
	running = 0;
	return 1;
}
