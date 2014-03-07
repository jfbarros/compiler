#include <stdio.h>

int main (int argc, char **argv)
  {
     int I;
     int J;
     for (I = 1 ; I <= 10 ; I++){
         for (J = 1 ; J <= I ; J++){
             printf("%d ",J);
         }
         printf("\n");
     }
  }
