/*
Title: pow.cpp
Author: Chris Aggeles
Email: aggeles@uga.edu
Purpose: practice recursive and iterative methods
Function: A given set of integers are raised to a given set of powers
Output: Program displays given integers raised to given powers
	for both iterative and recursive functions
Complexity: Iterative: O(n), where n is the magnitude of the exponential power.
	    Recursive: O(n), where n is the magnitude of the exponential power.
*/
#include <iostream>
using namespace std;

int itPow(int, int);
int recPow(int, int);


int main(){
int base;
int power;
cout << "Please enter the base number" << endl;
cin >> base;
cout << "Please enter the power" << endl;
cin >> power;
cout << "The result of raising " << base << " to the power of " << power<< " is " << itPow(base, power) << ", iteratively\nand " << recPow(base, power) << ", recursively " << endl;	
	
}//endmain


int itPow(int base, int power){

	int result = 1;

	for(int i = 0; i < power; i++){

	result *= base;

	}
	if( power < 0) {
	result = 1/result;
	}
	if( power == 0)return 1;
	
	return result;

	}//end itPow

//first time through, result must be entered as one
int recPow(int base, int power){
	if(power == 1) return base;	
	if(power == 0) return 1;
	if(power < 0 ){ 
	return 1/(base*recPow(base, power));
	}
	cout << "got here" << endl;
	return base*recPow(base, power-1);
	}//end recPow
