/*
Title: bstInsert

Author: Chris Aggeles

Email: aggeles@uga.edu

Purpose: To use recursion to create a method for insertion into a binary tree

Key Ideas: It was really only necessary to differentiate between 
larger or smaller data in the node versus a given insertion point, and
then work one's way gradually down the tree until its place was found. 

Sample I/O: The program has a built in main() that will handle the testing.
The program is designed to insert nodes into a tree that is initially empty,
and then gradually add more nodes (while stopping every two or three adds to
print out its progress) until a final set is reached. 

So, the program would look like this:

//begin output
Inserted (some number), then (some other random number), tree data in order is:

(print out in order data set from binary tree)

(repeat above 2 steps until entire data set is inserted and printed)
//end output


The data set included can be readily seen in the struct declarations below. 
I tried to pick random numbers during declaration, to test to see if order 
of insertion would affect the effectiveness of the implementation, but also 
such that lots of branching would inevitably happen. 

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

bstNode* bstInsert(bstNode *root, bstNode *newNode);


int main(){


//build tree by inserting one node at a time
//first bstInsert() call gets 0 as root because tree is empty
//could also have used root as the root for the call instead, but
//the logic is a little more sensible to me this way

bstNode * root = new bstNode(10);

root = bstInsert(0,root);

bstNode * n1 = new bstNode(4);

root = bstInsert(root, n1);

bstNode * n2 = new bstNode(7);

cout << "\nInserted 10, then 4, tree data in order is: " << endl;

printInorder(root);

root = bstInsert(root, n2);

bstNode * n3 = new bstNode(2);

root = bstInsert(root, n3);

bstNode * n4 = new bstNode(5);

root = bstInsert(root, n4);

bstNode * n5 = new bstNode(15);

cout << "\nInserted 7, then 2, then 5, tree data in order is: " << endl;

printInorder(root);

root = bstInsert(root, n5);

bstNode * n6 = new bstNode(12);

root = bstInsert(root, n6);

bstNode * n7 = new bstNode(8);

root = bstInsert(root, n7);

bstNode * n8 = new bstNode(6);

root = bstInsert(root, n8);

cout << "\nInserted 15, then 12, then 8, then 6, tree data in order is: " << endl;

printInorder(root);

bstNode * n9 = new bstNode(22);

root = bstInsert(root, n9);

bstNode * n10 = new bstNode(17);

root = bstInsert(root, n10);

cout << "\nFinal insertion of 22 then 17, tree data final in order is: " << endl;

printInorder(root);

cout <<"\n"<<endl;
//all she wrote
return 0;
}//end main





bstNode * bstInsert(bstNode * root, bstNode * newNode){

   //base case
  if (root == 0) root = newNode; 
   //either go left or right
  else {  
    if (newNode->data <= root->data)
	{ 
	
	root->left = bstInsert(root->left, newNode);
	 
	}
    else root->right = bstInsert(root->right, newNode);
    return root;  
  } 

return root;
}


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
