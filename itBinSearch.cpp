/*
Title: itBinSearch.cpp
Author: Chris Aggeles
Email: aggeles@uga.edu
Purpose: To learn about iterative implementation 
	of binary search algorithm
Input: Program contains a sorted list of numbers and a list of targets
	that may or may not be in that list. 
Function: The program iteratively searches through the list and 
	return what values from the target list are found.
Output: Output shows the given list to be searched and then a list
	of the targets and theie respective indices in that given list.
	If they are not found, an index of -1 is returned.
*/


#include<iostream>
#include <vector>
using namespace std;
//index of target in list is returned (-1 returned if the target is not present)
int binSearch(vector<int>, int);

int main(){
//the source list
vector<int> list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//the list of targets to be searched for in the source list
vector<int> targetList = {1, 5, 12, 20};

	cout << "The results of the iterative binary search are as follows:\n\n"
	<< "For the array {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}:\n" << 
	"the following targets were found at the following indices: \n\n"
	 << "(please note that an index of -1 denotes the absence\nof the target in the array)\n" << endl; 
	for(int i = 0; i < targetList.size(); i++){  
	cout <<	targetList.at(i) << " found at index: " << binSearch(list, targetList.at(i)) << endl;
	}//endfor
return 0;
	
}//endmain


int binSearch(vector<int> list, int target){
int start = 0;
int end = list.size()-1;

	while(start < end){

	int midpoint = (start + end)/2;

	if(target < list.at(midpoint)){
	end = midpoint - start;
	}
	else if(target > list.at(midpoint)){
	start = midpoint + start;
	}
	else return midpoint;
	}//endwhile

	//defaults to -1 if target not found
	return -1;
		
}//end search	 
