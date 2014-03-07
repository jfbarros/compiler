/*
 * ReturnTest.c
 *
 *  Created on: Jan 8, 2014
 *      Author: junior
 */

#include <stdio.h>
#include <stdlib.h>

int Input(int numA){

	printf("\nNumber to A (in function).. ");
	scanf("%d",&numA);

	return numA;
}

int main(){
	int numA=0,calc=5;
	calc = calc + Input(numA);
	printf("\nNumber to A (after return).. %d",calc);
	return 0;
}

