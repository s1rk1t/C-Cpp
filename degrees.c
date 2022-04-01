#include<stdio.h>

main(){

float ctemp;
printf("Enter a temperature in Celsius: \n");
scanf("%f", &ctemp);


float ftemp = ctemp * 9/5 + 32;

printf("%.2f degrees Celsius converts to %.2f degrees Fahrenheit\n", ctemp, ftemp);

}
