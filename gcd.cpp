/*
Title: gcd.cpp
Author: Chris Aggeles
Email: aggeles@uga.edu
Purpose: Practice with recursive and iterative solutions to numeric problems
Interface: Two integers are requested from user
Function: Given two integers, the program will iteratively and recursively
	determine their greatest common divisor
Output: For the pair of integers entered by the user, the greatest common
	divisor will be displayed
*/
#include <iostream>
using namespace std;


int itGCD(int, int);
int recGCD(int, int, int);

int main(){
int alpha;
int beta;
cout << "Input the first integer: " << endl;
cin >> alpha;
cout << "Input the second integer: " << endl;
cin >> beta;

cout << "The greatest common divisor of " << alpha << " and " << beta 
	<< " is:\n " << recGCD(alpha, beta, 0) << ", recursively and: " << itGCD(alpha, beta) << ", iteratively." << endl;
 
return 0;
}//endmain

int recGCD(int firstNum, int secNum, int commonDivisor){
	//base case, if common divisor is one, then there are none left
	if(commonDivisor == 1) return 1;

	int biggest;
	int smallest;
	commonDivisor = 1;
	
	if(firstNum>secNum)
	{
		biggest = firstNum;
		smallest = secNum;
	}
	else 
	{
	biggest = secNum;
	smallest = firstNum;
	}
	//the divisor won't be any bigger than the quotient 
        for(int i = 2; i <= smallest; i++){

                if((biggest%i == 0) && (smallest%i == 0))
                {
                commonDivisor = i;
                break;
                }//endif
        }//endfor
                return commonDivisor*(recGCD(biggest/commonDivisor, smallest/commonDivisor, commonDivisor));
}//end recGCD
 
//iteratively decrementing possible divisors from size of smallest down to one
int itGCD(int firstNum, int secNum){
int biggest;
int smallest;
int GCD = 1;
	if(firstNum > secNum)
	{
	biggest = firstNum;
	smallest = secNum;
	}
	else 
	{
	biggest = secNum;
	smallest = firstNum;
	}
	for(int i = smallest; i > 1; i--){
		if((biggest % i == 0) && (smallest%i == 0)){
			GCD = i;
			break;
		}
	}

	return GCD;
}//end getGCD

//end gcd.cpp
