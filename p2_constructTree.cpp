/*
Title: constructTree

Author: Chris Aggeles

Email: aggeles@uga.edu

Purpose: to construct a binary tree from given preordered and 
inordered sequences

Key Ideas: Figuring out the precedent structure for the given ordererings was
critical to implementing the binary tree construction. For instance, if
a given node is on the far left of the preorder, then one knows that everything
to the left of that node in the inorder sequence comprises the left branch
of the tree. 

Sample I/O: The program has a built in preorder and inorder sequence from
which a binary tree is built. Then, a method is invoked to display the
inorder sequence of the newly built tree. To demonstrate that the newly built
tree is the same as the one determined from the initial to sequences, the
program outputs the initial inorder sequence before the tree is built
and then signals that the tree is being built. Once it's built, it outputs
the newly constructed tree's inorder sequence, which should be the same as 
the inorder sequence given intially.

So, output will be like:

//begin output
<paraphrase> The inital in order sequence is:

<print out sequence>

<display message when tree is built>

<paraphrase> The in order sequence of the newly constructed tree is:

<print out inorder via method>

//end output 


*/

#include<vector>
#include<string>
#include<iostream>

using std::cout;
using std::endl;
using std::vector;

struct node {

	int data;
	node * left;
	node * right;
	node * parent;
	node(int x): data(x), left(0), right(0) {}

};
void printInorder(node * root);

node * buildTree(vector<int> &, vector<int> &);

node * getBinaryTree(vector<int> &, vector<int> &, int, int, int, int);

int main(){

    int a[] = {6,9,3,4,1,2,7,12};

    int b[] = {3,9,4,1,6,12,7,2};
//	int b[] = {1, 2, 3, 4, 6, 7, 9, 12};
	vector<int> preorder (a, a + sizeof(a)/sizeof(int) );
	vector<int> inorder (b, b + sizeof(b)/sizeof(int) );
	
	node * root = buildTree(preorder, inorder);
	cout << "\nThe in order sequence before the tree is constructed is: " << endl;
	cout << "\n3, 9, 4, 1, 6, 12, 7, 2" << endl;

	cout << "\nNow the tree is being built!" << endl;

	cout << "\nThe in order sequence of the reconstructed tree is:\n " << endl;
	printInorder(root);

	cout << "\n" << endl;
		
	

	//root is head of reconstructed binary tree	

return 0;

}//end main

void printInorder(node * root)
{
    if(root != NULL)
    {
        if(root->left)
        {
            printInorder(root->left);
            cout << ", ";
        }

        if(root->data)cout << root->data;

        if(root->right)
        {
            cout << ", ";
            printInorder(root->right);
        }

   }
}



node * buildTree(vector<int> &preorder, vector<int> &inorder){

	int a = preorder.size();

	return getBinaryTree(inorder, preorder, 0, a, 0, a); 

}//end buildTree

//l1 = istart l2 = pstart r1 = iend r2 = pend
node * getBinaryTree(vector<int> & iorder, vector<int> & porder, int istart, int iend, int pstart, int pend){

	if(istart > iend|| pstart > pend || iend > porder.size() || pend > iorder.size()) return NULL;
	
	node * root = new node(porder[istart]);

	int index;

	for(index = pstart; index <= pend; index++){

		if (iorder[index] == porder[istart]) break;	

	}
	
	root->left = getBinaryTree(iorder, porder, istart+1, istart+index-pstart, pstart, index);

	root->right = getBinaryTree(iorder, porder, istart+1+index-pstart,iend,index+1, pend);

	return root;

}//end bt

