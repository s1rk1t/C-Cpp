/*
Title: maze.cpp

Author: Chris Aggeles

Email: aggeles@uga.edu

Purpose: the determine if a viable path is present in a given maze.

Key Ideas: Much like the hanoi problem, recursion was a critical
component of solving the maze. 

Sample I/O: The maze used by the main method is the on given in
the homework text. Any viable maze could be used with the same logic, but
for simplification the given maze was used. The program will analyze the given
maze and output a statement that it is true that the given maze may 
be navigated, or else it will output that it is false. 
*/

#include<iostream>
#include<string>
using std::string;
using std::endl;
using std::cout;

bool isPath(int[][4], int, int);

int main(){
	//4 x 4 maze is used
	//goal space is 4,4
	int maze[][4] = {{1,0,0,0},{1,1,0,1},{0,1,1,1},{1,1,1,1}};
	//starting point is 0,0 in this instance 
	//however, any starting point would work
	bool result = isPath(maze, 0, 0);

	string answer;

	if(result == 1) answer = "true";
	else answer = "false";

	cout << "The program computes that it is " << answer << " that the maze has a path." << endl; 


}

bool isPath(int maze[][4],int x, int y){
	
	//these are the constraints that set the boundaries
	//anything beyond the contraints will return false
	if((x > 3) || (x < 0) || (y >3) || (y < 0)) return false;
	//if goal is reached, return true
	//in this instance, goal is (4,4) which means
	//y = 3 and x = 3, as they start at index 0
	else if((x == 3) && (y == 3)) return true;
	//can't move on a node with a 0 per instructions, 
	//any other fitness function would also be relevant
	else if(maze[x][y] == 0) return false;
	//if it's possible to find the end going in any direction
	//the program returns true
	else if(isPath(maze, x, y+1) == true) return true;
	else if(isPath(maze, x+1, y) == true) return true;
	else if(isPath(maze, x, y-1) == true) return true;
	else if(isPath(maze, x-1, y) == true) return true;
	//if you get this far, there has been no succesful 
	//path within constraints
	return false;
}




