/*
Title: listCycle.cpp

Author: Chris Aggeles

Email: aggeles@uga.edu

Purpose: to determine if a loop is present in a linked list

Key Ideas: The critical logical leap was made when I figured out that given two pointers on a list, one moving up the list at twice the rate of the other,
one can deduce that if there is a loop present, the two pointers
will eventually point to the same node. Implementation followed naturally.

Sample I/O: The program constructs two linked lists in its main method. It then
runs the loop checking method and outputs the boolean result of the method
to the user. E.g. "This program think that it is <boolean result> that the loop
with (or without, this part will be preprogrammed to reflect whether the list
has a loop or not) has a loop in it. The first list has a loop built in and the second one does not.
*/

#include"node.cpp"
#include<iostream>
#include<string>

using std::string;
using std::cout;
using std::endl;

bool checkCycle(node * head);

int main(){

//these nodes will comprise the first list
//there IS a loop in it, from the tail to the head

node * head1 = new node();
node * node2 = new node();
node * node3 = new node();
node * node4 = new node();
node * tail1 = new node();

head1->next = node2;
node2->next = node3;
node3->next = node4;
node4->next = tail1;
tail1->next = head1;

bool result = checkCycle(head1);//should return true

string answer = "false";

if (result == true) answer = "true";

cout << "This program thinks it is " << answer << " that the list with a cycle has a cycle in it." << endl;

//this node set is used to construct the second list
//it does NOT have a loop in it, so the checkCycle should return "false"

node * head2 = new node();
node * nodeA = new node();
node * nodeB = new node();
node * nodeC = new node();
node * tail2 = new node();

head2->next = nodeA;
nodeA->next = nodeB;
nodeB->next = nodeC;
nodeC->next = tail2;
tail2->next = 0;

result = checkCycle(head2);//should return false
if(result == true) answer = "true";
else answer = "false";

cout << "This program thinks it is " << answer << " that the list without a cycle has a cycle in it." << endl;
	
}

bool checkCycle(node * head){

	if(head == 0) return false;
	node * tempHead = head;
	node * loopCatcher = head->next;

	while(loopCatcher){

		tempHead = tempHead->next;
		if (loopCatcher->next == 0) return false;
		loopCatcher = loopCatcher->next->next;

		if (tempHead == loopCatcher) return true;

	}//end while

	return false;
		
}//end checkCycle




	
