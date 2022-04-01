/*
Title:bstMinimum

Author:Chris Aggeles

Email: aggeles@uga.edu

Purpose: to use the idea of recursion and knowledge of the structure of 
a binary tree to seek out the global minimum.

Key Ideas: In the case of a binary tree, a global min is found 
through an exploration of the leftmost branch of a *root* node, which is
the *given* node in the parameter list in the homework 7 description.
Hence, the O(n) where n is the number of leftmost branches possible, which is 
analogous to the algorithm described above, in that the algorithm would 
only execute a maximum number of n times to reach that branch.


Sample I/O: Inside of the main program, a sample binary tree is constructed
using bstNodes as units. After the tree construction is finished, a method
that determines a given root's global minimum is run. The inorder is then 
outputted to the screen, followed by a determination of the global min.

So, output will be:

//start output
In order data set of binary tree is:
(output in order tree data set)
Global min is:
(output global min)
//end output 

*/


#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::string;
using std::cin;



struct bstNode {
int data;
bstNode *left;
bstNode *right;
bstNode *parent;
bstNode(int x): data(x), left(0), right(0) {}
};

void printInorder(bstNode * root);
bstNode* bstMinimum(bstNode *root);

int main(){
//initialize nodes
bstNode * n1 = new bstNode(0);
bstNode * n2 = new bstNode(2);
bstNode * n3 = new bstNode(5);	
bstNode * root = new bstNode(8);
bstNode * n5 = new bstNode(10);
bstNode * n6 = new bstNode(15);
bstNode * n7 = new bstNode(17);
bstNode * n8 = new bstNode(20);

//create binary tree 
root->right = n6;
root->left = n2;
n2->right = n3;
n2->left = n1;//n1 is global min, data == 0
n6->left = n5;
n6->right = n7;
n7->right = n8;

bstNode * solution = bstMinimum(root);


cout << "\nIn order data set of binary tree in main() is: " << endl;

printInorder(root);

cout << "\nGlobal minimum is: " << solution->data << endl;


//output global min, which in this case is 0.


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


//pretty simple recursive function, just goes to the left if possible
//and eventually returns the leftmost node.
bstNode * bstMinimum(bstNode * root){

	if(!root->left) return root;

	return bstMinimum(root->left);

	
}//end bstNode


