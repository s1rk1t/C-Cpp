#include<stdio.h>

main()
{


printf("Enter two integers: ");

int firstNum;
int secondNum;

scanf("%d%d", &firstNum, &secondNum);


if((firstNum || secondNum) == 0){
printf("Please restart the program and enter two nonzero numbers.");
}

int sum = firstNum + secondNum;

printf("Sum: %d\n", sum);

double average = (double)(firstNum + secondNum)/2;

printf("Average: %f\n", average);

int squareSum = firstNum*firstNum + secondNum*secondNum;
printf("Sum of squares: %d\n", squareSum);

return 0;

}//end main
