/*
 * TrigonometricFunctions.c
 *
 *  Created on: Jan 9, 2014
 *      Author: junior
 */

#include <stdio.h>
#include <math.h>
/*
float Sin(float angle){
	float resultSin;
	resultSin = sin(angle);
	return resultSin;
}

float Cos(float angle){
	float resultCos;
	resultCos = cos(angle);
	return resultCos;
}

float Tan(float angle){
	float resultTan;
	resultTan = tan(angle);
	return resultTan;
}*/

int main(){
	float angle=0.0,sin,cos,tan;
	printf("\nEnter with a angle.. \n");
	scanf("%f",&angle);
	sin = sin(angle);
	cos = cos(angle);
	tan = tan(angle);
	printf("\nSeno: %.4f",sin);
	printf("\nSeno: %.4f",cos);
	printf("\nSeno: %.4f",tan);
	return 0;
}
