/*
Title: fib.cpp
Author: Chris Aggeles
Email: aggeles@uga.edu
Purpose: calculate Fibonacci number given index in Fibonacci sequence
Input: Program is given first 20 numbers of Fibonacci sequence.
Output: The 20 respective Fibonacci values
Function: The Fibonacci sequence is a sequence of aggregative addition, 
	where the current number of teh sequence is the sum of the two previous
	numbers. The sequence begins : 0,1
Complexity: Recursive is O(2^n) Iterative is O(n)
*/
using namespace std;
#include <iostream>
int itFib(int);
int recFib(int, int, int);


int main(){

cout << "The fortieth Fibonacci number is: " << itFib(40) << " using the iterative function and: " << recFib(40, 0, 1) << " using the recursive function. " << endl;

return 0;

}//end main
int itFib(int n){
int fib1 = 0;
int fib2 = 1;
int temp;
	for(int i = 0; i < n; i++){
	 temp = fib1;
	fib1 = fib2;
	fib2 = temp+fib1;
	}//endfor
	return fib1;
}//end itFib

int recFib(int n, int fib1, int fib2){
	if(n == 1) return fib2;
	int temp = fib1;
	fib1 = fib2;
	fib2 = temp+fib2;
	n--;
	return recFib(n, fib1, fib2);
	}//end recFib



