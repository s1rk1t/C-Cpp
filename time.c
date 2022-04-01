#include<stdio.h>

main(){

int totalsecs;

printf("Enter in the total number of seconds as an integer: ");
scanf("%d", &totalsecs);

int hours = totalsecs / 3600;

int minutes = (totalsecs % 3600) / 60;

int secs = totalsecs - hours*3600 - minutes*60;
if(hours == 1){
printf("\n %d seconds is equivalent to %d hour %d minutes %d seconds", totalsecs, hours, minutes, secs);
}//endif
else printf("\n %d seconds is equivalent to %d hours %d minutes %d seconds.\n", totalsecs, hours, minutes, secs);

}
