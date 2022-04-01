/*
Title: swap.cpp 
Author: Chris Aggeles
Email: aggeles@uga.edu
Purpose: Reinforce methodology used to perform swap without third variable
Advantages: overhead efficiency goes up as less space and time are used
Interface: No user input is required, the two swapped integers are 
	defined in main() as alpha and beta. 
Function: swap() performs bitwise 'exlcusive or' operation on two integers
Output: Program displays integers before their swap and then after 
*/
#include<iostream>
#include<sstream>
using namespace std;


void swap();

int main(){
int alpha= 10;
int beta = 20;

	
        //output data to screen
        cout << "Before swap, value of alpha is: " << alpha << endl;
        cout << "Before swap, value of beta is: " << beta << endl;
       	//meat and potatoes, performs the bitwise ^= operation
	swap(alpha, beta);
	//tell em what they've won, Johnny!
        cout  << "Swap completed!" << endl;
	//now prove it!
        cout  << "Alpha now equals: "<< alpha << endl;
        cout << "Beta now equals: " << beta << endl;
	 
//that's all folks!
return EXIT_SUCCESS;

}//end main

//this method uses the exclusive or operation as shown in class
//integers parameters are passed by reference as they will be needed outside
//of the function during the output

void swap(int &alpha, int &beta){
	
// ^= characters denote bitwise equivalent to 'exclusive or' logical operation

beta ^= alpha;
alpha ^= beta;
beta ^= alpha;

}//endswap

//end swap.cpp
