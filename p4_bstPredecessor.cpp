/*
Title: bstPredecessor

Author: Chris Aggeles

Email: aggeles@uga.edu

Purpose: to determine the in order predecessor (if there is one) 
for a given node in a binary tree.

Key Ideas: Directionality came into play when figuring out the logic.
Essentially there are a few movements within the tree that are necessary
to discover the predecessor (if not at global min), and so conditional
logic made implementing that very simple given that there are only so many
directions one might go from a given node.

Sample I/O: The code is written to display a sample binary tree in order
and then look for the predecessor in randomly predetermined nodes 
in that tree. So output would be:

//begin output
<paraphrasing>In order data for the the tree is:

<print out in order data>

<paraphrasing>The predecessor for node 4 (data=2) is: 

<output predecessor or throw message exception if node is global min>

<repeat several times with different nodes, stopping to output the in order
sequence ever so often to remind user of data set's order of precedence.>

<termination message>
//end output

*/

#include<iostream>

using std::cout;
using std::endl;

struct bstNode {
int data;
bstNode *left;
bstNode *right;
bstNode *parent;
bstNode(int x): data(x), left(0), right(0) {}
};

void printInorder(bstNode * root);
bstNode* bstPredecessor(bstNode *curr);

int main(){

//declare nodes
bstNode * root = new bstNode(10);
bstNode * n2 = new bstNode(6);
bstNode * n3 = new bstNode(5);
bstNode * n4 = new bstNode(3);
bstNode * n5 = new bstNode(7);
bstNode * n6 = new bstNode(0);
bstNode * n7 = new bstNode(20);
bstNode * n8 = new bstNode(15);
bstNode * n9 = new bstNode(25);
bstNode * n10 = new bstNode(13);

//construct binary tree
root->left = n2;
root->right = n7;
n2->parent = root;
n7->parent = root;
n2->right = n5;
n2->left = n4;
n5->parent = n2;
n4->parent = n2;
n4->right = n3;
n4->left = n6;
n3->parent = n4;
n6->parent = n4;
n7->right = n9;
n7->left = n8;
n9->parent = n7;
n8->parent = n7;
n8->left = n10;
n10->parent = n8;

bstNode * solution;

//first example should return predecessor to root, which is n5
solution = bstPredecessor(root);

cout << "\nFor binary data tree with data in the following order: \n" << endl;

printInorder(root);
cout << "\n\nPredecessor data to root (data = 10) is: " << solution->data << endl;

//next example is global minimum, so no predecessor should be available
//program will return global min and print out notification message
cout << "\nPredecessor to node 6 (data = 0) is : " << endl;

solution = bstPredecessor(n6);
//error handled within method

cout << "\nFor binary tree with data in the following order: \n" <<endl;

printInorder(root);
//next let's try one from the right side of the tree
//solution should be "13"
solution = bstPredecessor(n8);

cout << "\n\nPredecessor data to node 8 (data = 15) is: " << solution->data << endl;

//now one from the left side that's not the global min
//solution should be "6"
solution = bstPredecessor(n5);

cout << "\nPredecessor data to node 5 (data = 7) is: " << solution->data << endl;
cout <<"\nThat's the end of our tests!\n\nGood bye! :) \n" <<endl;

//all she wrote
return 0;

}//end main

void printInorder(bstNode * root)
{
    if(root != NULL)
    {
        if(root->left)
        {
            printInorder(root->left);
            cout << ", ";
        }

        cout << root->data;

        if(root->right)
        {
            cout << ", ";
            printInorder(root->right);
        }

   }
}


bstNode * bstPredecessor(bstNode * curr){

	bstNode * solution;

	
		//if it fails all conditions, must be root
		solution = curr;
		
		if(curr->left){

			solution = curr->left;
			
			if(curr->left->right){
	
			solution = curr->left->right;
	
			bstNode * temp1 = curr->left->right;
	
				while(temp1->right){
					temp1 = temp1->right;
					solution = temp1;
				}//end while
			}//end last if	
		}//end first
	 	else if(curr->parent->right == curr) solution = curr->parent;
		
		else if(curr->parent->left == curr){
			
			bstNode * temp2 = curr;

			while(temp2->parent->left){
		
				temp2 = temp2->parent;
				if(temp2->parent == 0){

					cout << "No predecessor, node is global minimum!" << endl;
				return curr;
			
				}
				else if(temp2->parent->right == temp2){
				
				solution = temp2->parent;
				return solution;
				}
			}//end while
		}
		return solution;
}//end bstPredecessor
