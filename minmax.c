#include<stdio.h>

main(){

int array[10];
int index;

printf("Enter in 10 integers:\n ");

for (index = 0; index < 10; index++)

{

scanf("%d", &array[index]);

}

int min = array[0];
int max = 0;
int j;

for (index = 0; index < 10; index++)

{

if (array[index] < min){
min = array[index];

}

}

for(j = 0; j < 10; j++){

if(array[j] > max){
max = array[j];

}

}

printf("Min: %d\n", min);
printf("Max: %d\n", max);


}
