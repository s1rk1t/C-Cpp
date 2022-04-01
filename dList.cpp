/*
Title: dList.cpp

Author: Chris Aggeles

Email: aggeles@uga.edu

Purpose: to work with the data structure: doubly linked lists

Key Ideas: Checking for cases became a key component to proper
code execution. This means checking if a node is the head, tail,
if tail->next is null, etc. The rest of the logic was dependent on 
knowledge of the linking structure.

Sample I/O: provided by tester file

*/

#include"dList.h"
#include<iostream>
#include<cstdlib>

using std::cout;
using std::endl;
using std::exit;

dList::dList(){

node * head;
node * tail;	

}

//destructor
dList::~dList(){
}

void dList::push_front(int val){


	
	//if no head, make one
	if(head->data > 1000000 || head->data < -1000000){

	
		head = new node(val);
	
		tail = head;
		
	}
	else{
		

		node * temp = new node(val);
		head->prev = temp;
		
		temp->next = head;
		
		head = temp;
	
	
	}

}

void dList::push_back(int val){

	//only way possible is if there is no head
	if(tail == 0){

		node * temp = new node(val);
		tail = temp;
		head = temp;

	}

	else{

		node * temp = new node(val);
		tail->next = temp;
		temp->prev = tail;
		tail = temp;

	}
		
}

void dList::pop_front(){

	if(head == 0) cout << "No head present!" << endl;
	else{
		node * garbage = head;
		node * temp = head->next;
		head = temp;
		delete garbage;
	}

}

void dList::pop_back(){

	if(tail == 0) cout << "No tail to pop!" << endl;

	else{

		node * garbage = tail;
		node * temp = tail->prev;
		tail = temp;
		delete garbage;

	}//end else
}

int dList::front(){

	return head->data;

}

int dList::back(){

	return tail->data;

}

void dList::insert(int position, const int& val){
	
	int size = this->size();
	node * insertedNode = new node(val);
		
	//first position 
	if(position == 1){
	
		push_front(val);	

	}
	//last position
	else if(position == size+1){

		push_back(val);
	}
	else if(position > size+1){

	cout << "terminate called after throwing an instance of of 'std::logic_error' what(): The list has " << size << " elements, you cannot insert element to be in " << position << "th position" << endl;
	exit(-1);
	}
	else{	
	node * insertPointB = head;
	
	for(int i = 1; i < position; i++){
		
		insertPointB = insertPointB->next;
			
		}//end for
	
	//Logic is InsertPointA->InsertedNode->InsertPointB

		node * insertPointA = insertPointB->prev;
		insertPointA->next = insertedNode;
		insertedNode->prev = insertPointA;
		insertedNode->next = insertPointB;
		insertPointB->prev = insertedNode;

	}//end else

}//end insert

void dList::remove(const int& val){



	node * removedNode = 0;
	node * temp = head;
	if((head->data == tail->data) && (head->data == val)) head = tail = 0;

	while(temp){
	
		if(temp->data == val){

			removedNode = temp;
			break;
		}
	
		temp = temp->next;
			
	}//end while
  		
	if(removedNode == 0) cout << "The list has no node with the value " << val << endl;
	
	else{
	//Logic is from 
	//removalPointA-><-removedNode-><-removalPointB
	//to removalPointA-><-removalPointB
	if(removedNode == head) head = head->next;
	else if(removedNode == tail){
		 tail = tail->prev; 
	}
	else{ 
	 node * removalPointA = removedNode->prev;
	 node * removalPointB = removedNode->next;
	
	removalPointA->next = removalPointB;
	removalPointB->prev = removalPointA;
	}//end second else
	}//end first else

}//end remove


int dList::size(){
	int size = 0;
	node * temp = head;
	if(head == 0 && tail == 0) return 0;

	else if(head == tail) return 1;

	else{


	while(temp){
		size++;
		temp = temp->next;
		}//end while

	}//end else
	return size;
}//end size

bool dList::empty(){

	if((head == 0) && (tail == 0)) return true;
	else return false;

}//end empty

void dList::print(){
	
	node * temp = head;
	node * temp2 = tail;
	if(head == 0) cout << "This is an empty list." << endl;
	
	else{

		while(true){
		
			cout << temp->data << " ";
			if((temp->next) && (temp2 != temp)) temp = temp->next;
			else break;
		
			}//end while
	cout << " " << endl;
		}//end else
}//end print
