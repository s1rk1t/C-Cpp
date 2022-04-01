/*

Title: arrayIntQueue.cpp

Author: Chris Aggeles

Email: aggeles@uga.edu

Purpose: Implement queue using array of integers

Key Ideas: Keeping track of front and rear positions while
making sure that array never becomes overfilled (n < capacity)

Sample I/O: sample I/O is given in homework document

*/

#include "arrayIntQueue.h"
#include<iostream>

using std::cout;
using std::endl;

queue::queue(){

//default capacity = 1024
capacity = 1024;
arr = new int[capacity];
f = 0;
r = 0;
n = 0;

}

queue::queue(int c){

capacity = c;
arr = new int[capacity];
f = r = -1;
n = 0;
}
queue::~queue(){
}
int queue::front(){
	//return value at array[front]
	return arr[f%capacity];
}
	
int queue::back(){
	//return value at array[rear]
	return arr[r%capacity];
	

}

int queue::size(){
	
	//return amount of nodes in queue
	return n;

}

bool queue::empty(){

	//if there are no elements, return true
	if(n == 0) return true;
	else return false;

}

void queue::print(){

	//cout all values in array
	if(n == 0) cout << "No values to return!" << endl;
	else{

		for(int i = 0; i < n; i++){

			cout << arr[(f+i)%(capacity)] << endl;
		}//end for
	}//end else
}//end print


void queue::push(int value){

	
	if(n == 0){
		
		f = r = 0;
		arr[f] = value;
		n++;
		}

	else if(n < capacity){
		r = (++r)%(capacity);
		//increment r relative to capacity and insert value
		arr[r] = value;
	
		n++;
	}

	else cout << "Array is full! No values can be added" << endl;


}//end push

void queue::pop(){
	if(n == 0) cout << "Array already empty!" << endl;
	else{
	
	f = (++f)%(capacity);
	n--;
	}//end else
}//end pop

//end arraIntQueue.cpp	
