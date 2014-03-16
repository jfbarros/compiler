#include "hash.h"
#include <stdio.h>

extern int running;
extern int yylex();
extern int getLineNumber();

// Johann trocará a main, temos que tirar essa depois dos testes
int main(){
    int token;    
    while( running ) {
        token = yylex();    
        printf("Token encontrado: %d\n", token);
    }
    hashPrint();
    printf("Numero de linhas: %d\n", getLineNumber());
	//yywrap();
	return 0;
}
