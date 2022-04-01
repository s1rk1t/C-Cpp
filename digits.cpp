/*
Title: digits.cpp
Author: Chris Aggeles
Email: aggeles@uga.edu
Purpose: To reinforce recursive vs. interative methodology via parsing
Interface: Program is run without user input
Function: Iteratively/recursively determines the number of digits in an integer
Output: For both iterative and recursive techniques, 
	each given integer is displayed along with 
	the number of digits it possesses.
Complexity: Complexity for the both versions is O(n)
*/
#include <iostream>
using namespace std;

int itDigits(int);
int recDigits(int);

int main(){

	int list[] = {123, -50, 6, -1, 0,};
	

	cout << "----------Iterative digit counter-----------" << endl;
	//6 is size of list
	for(int i = 0; i < 5; i++){
	
	cout << "The number of digits in " << list[i] << " is: " <<
	itDigits(list[i]) << endl;
	}//endfor

	cout <<"-----------Recursive Edition----------------" << endl;
	for(int i = 0; i < 5; i++){
	
	cout << "The number of digits in " << list[i] << " is: " << 
	recDigits(list[i]) << endl;
	}
return 0;	
}//end main
/*
Iterative function uses a while loop to increment a digit counter while
dividing the query by ten. Nearly identical logic to the recursive function
with a slightly different implementation
*/

int itDigits(int query){
	
int count = 0;
	//dividing each time by ten will shorten the query by one digit
	//each time this is done, the counter is incremented
	while(query/10 > 0){
	query = query/10;
	count++;
	}
	//should have one digit at this point, so add one to final digit count
	count++;
	return count;
}//end itDigits

/*
Recursive function divides by ten and tests against base case.
If it's not satisfied, the function adds one to the digit count and divides the query by ten before passing it further along the recursive tree
*/

int recDigits(int query){


	if(query/10 == 0) return 1;
	else return 1 + recDigits(query/10);

}//end recDigits

//end digits.cpp
