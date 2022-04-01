#include<stdio.h>

main(){


printf("Enter in a start time: ");

int start;

scanf("%d",&start);
printf("\nEnter in a duration: ");

int duration;

scanf("%d", &duration);

int startHours = start / 100;
int startMinutes = start - startHours * 100;
int totalMinutes = startHours * 60 + startMinutes + duration;
int finalHours = (totalMinutes / 60) * 100;
int finalMinutes = totalMinutes - ((finalHours / 100) * 60);
int endTime = finalHours + finalMinutes;

printf("\nEnd time is: %d\n", endTime);

}

