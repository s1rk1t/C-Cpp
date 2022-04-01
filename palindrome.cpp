/*
Title: palindrome.cpp
Author: Chris Aggeles
Email: aggeles@uga.edu
Purpose: Illustrate how recursive plaindrome function discussed 
	in class can be performed iteratively
Input: List of possible palindromes from homework text is used
Function: Determines if a word is a palindrome using iterative technique
Output: From the given list of string literals the program will output 
	the palindromes that are present in the list
Complexity: Complexity for algorithm is O(n/2) + (n/2 * c), where n is
	the length of the palindrome and c is the time taken to 
	compute the instructions 
*/

#include<iostream>
#include <string>
using namespace std;

bool isPal(string);

int main()
{
string list[] = {"nation", "madam","step on no pets", "leeve"};
	for(int i = 0; i < 4; i++){
		if(isPal(list[i]) == true){

		cout << "\"" << list[i] << "\"" << " is a palindrome." << endl;

		}//endif
	}//endfor
}
 
//where n is the number of pairs of letters in the target word
//and c is the time taken to compute each step of the algorithm

bool isPal(string query){

bool isPal = false;

	//while the first character is the same as the last character
	//there is still a chance that the query is a plaindrome
	while(query.at(0) == query.at(query.length()-1))
	{
		
		if((query.length() == 3) || (query.length() == 2))
			{ 
				isPal = true; 
				break;
			}
		else{	
			//if first and last letters match
			//substring should be from second letter 
			//to second to last letter
			query = query.substr(1, query.length()-2);
		}//end else
 
	
	}//end while
	
	return isPal;

}//end isPal

//end palindrome.cpp
