/*
Title: fact.cpp
Author: Chris Aggeles
Email: aggeles@uga.edu
Purpose: Determine efficacy of recursive vs. iterative technique
Interface: No user input is required, factorial is determined for number '40'
Function: Recursive and iterative factorial techniques are employed
Output: Displays list of first 20 positive integers 
	and their respective factorial
Complexity: The complexity of the recursive version is O(2^(log_base2(n)))
		The complexity of the iterative version is O(n)
*/
#include<iomanip>
#include<iostream>
using namespace std;


long itFact(long);
long recFact(long);

long itFact(long n){
long factorial = 1;
	for(long i = n; i > 0; i--){
		factorial *= i;
	}
	return factorial;
}//end itFact

long recFact(long n){	

	if(n == 0) return 1;
	else return n*(recFact(n-1));
}//end recFact


int main(){
	cout << " n" << "\t" << "find n! using iteration" << setw(6) << " " << "find n! using recursive" << "\n";
	cout << setfill('-') << setw(60) << "-" << endl;
	for(int i = 0; i <= 20; i++)
	cout << setfill(' ') << right << setw(2) << i << setw(29) << itFact(i) << setw(29) << recFact(i) << "\n";

}//end main


//end fact.cpp	
