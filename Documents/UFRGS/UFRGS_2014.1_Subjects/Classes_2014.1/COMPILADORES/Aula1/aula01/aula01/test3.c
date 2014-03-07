#include <stdio.h>

int main (int argc, char **argv)
  {     
     FILE * arquivo;     
     int num;
     int linhas = 0;
     int numNumeros = 0;
     arquivo = fopen("in2.txt","r");
     char c;
     int bNum = 0;
     
     while (!feof(arquivo)) {
       c = fgetc(arquivo);
       if (c >= '0' && c <= '9') {
         if (bNum == 0) {
           bNum = 1;
           numNumeros++;
         }
       } else if (c == '\n') {
         linhas++;
         bNum = 0;
       } else if (c == ';') {
         printf("%d ", numNumeros);
         numNumeros = 0;
         bNum = 0;
       } else {
         bNum = 0;
       }
       
     }
     fclose(arquivo);
     printf("\nLinhas fisicas: %d\n", linhas);
  }
