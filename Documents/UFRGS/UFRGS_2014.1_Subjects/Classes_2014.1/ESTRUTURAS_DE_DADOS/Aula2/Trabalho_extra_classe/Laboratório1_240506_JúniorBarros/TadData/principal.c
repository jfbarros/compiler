/*
Laboratório 1 - Estruturas de Dados - 2014/1 
INSTITUTO DE INFORMÁTICA - Eng. de Computação
UNIVERSIDADE FEDERAL DO RIO GRANDE DO SUL

Autores:

Júnior Barros (Aluno) matrícula: 240506
principal.c - funções que identificam páscoa e ano bissexto

Renata Galante (Professora)
data.h, data.c - protótipo e funções de data (struct)
principal.c - entrada de dados e validação de data

OBSERVAÇÃO:
Em linux ligar arquivos data.c, data.h e principal.c compilar e gerar .bin
usar seguinte sequência de comandos (testado em linux mint 16(Petra)):
gcc principal.c data.h data.c -o principal.bin
./principal.bin
*/

# include <stdio.h>
# include <stdlib.h>
# include "data.h"

int dataPascoa(int ano)
{
	/*Cálculo de dataPascoa baseada em entrada de ano
fonte: http://astro.if.ufrgs.br/pascoa.htm
*/
	int a=ano,c,d,n,k,i,j,l,m;
	c = a/100;
	n = a-19*(a/19);
	k = (c-17)/25;
	i = c-c/4-(c-k)/3+(19*n)+15;
	i = i-30*(i/30);
	i = i-(i/28)*(1-(i/28))*(29/(i+1))*((21-n)/11);
	j = a+a/4+i+2-c+c/4;
	j = j-(7*(j/7));
	l = i-j;
	m = 3+((l+40)/44);
	d = l+28-(31*(m/4));
	printf("Data da páscoa: %d/%d/%d\n",d,m,a);
}
/*Cálculo de ano bissexto
http://pt.wikipedia.org/wiki/Ano_bissexto
*/
int anoBissexto(int ano)
{
 	if(((!(ano%4))&&(ano%100))||(!(ano%400)))
	{
		printf("É bissexto\n");
		return 1;
	}
	else
	{
		printf("Não é bissexto\n");
		return 0;
	}
}

int main (void)
{
    Data d;
	int retornoBissexto=0;
    le_data(&d);
    if (valida_data(d))
    printf("data valida\n");
    else printf("data invalida\n");
    dataPascoa(d.ano);
	retornoBissexto = anoBissexto(d.ano);
	printf("Retorno de função bissexto: %d\n\n",retornoBissexto);
    system("pause");
    return 0;
}
