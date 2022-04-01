/*
Title: hanoi.cpp

Author: Chris Aggeles

Email: aggeles@uga.edu

Purpose: To implement algorithm that will solve towers of Hanoi problem

Key Ideas: Recursion ended up being the most 
useful implementation technique. It helped to think about the problem 
in terms of the base case, and then the ordering logic necessary to 
get from one end to the other was the only other code necessary. Thinking
about the pegs as being (arbitrarily) a starting point, an ending point, and
an intermediary point was the most critical logical leap necessary to solving
the hanoi problem.

Sample I/O: The program will prompt the user for the number of disks
to be moved. It will then output the steps, one per line, to move all of 
the disks from peg a to peg c. 

*/
#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;


void hanoi(int, char, char, char);

int main(){


int disks;

cout << "Please enter the number of disks: ";
cin >> disks;
	

hanoi(disks, 'a', 'b', 'c');


return 0;

}//end main

//temp == intermediate step between start and destination
//critical for logic to work

void hanoi(int disks, char start, char finish, char temp){

	//base case, move smallest disk to destination	
	if(disks == 1){

	cout << "Move disk " << disks << " from peg " << start << " to peg " << finish << endl;

	}
	else{
		
		hanoi(disks-1, start, temp, finish);
		
		cout << "Move disk " << disks << " from peg " << start << " to peg " << finish << endl;
	
		hanoi(disks-1, temp, finish, start);

	}
}//end hanoi

 
