#include <stdio.h>

int main (int argc, char **argv)
  {     
     FILE * arquivo;     
     int num;
     int numNumeros = 0;
     arquivo = fopen("in2.txt","r");
     char c;
     
     while (!feof(arquivo)) {
       if (fscanf(arquivo, "%d",&num) == 1) {     
          numNumeros++;
       } else if (!feof(arquivo)) {
          c = fgetc(arquivo);
          printf("%d ", numNumeros);
          numNumeros = 0;
       }
     }
     fclose(arquivo);
     
  }
