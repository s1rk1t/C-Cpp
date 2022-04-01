/*
Title: postorderTraversal

Author: Chris Aggeles

Email: aggeles@uga.edu

Purpose: to print out the nodes of a binary tree in postorder

Key Ideas: traversing the tree is essentially a matter of deciding what
the relative position of the node is 

Sample I/O: A binary tree will be displayed for the user, then the postOrder()
function call will execute, and the program will output the post order
of the given binary tree for the user.

So, output would look like:

//begin output

<tree display>

<post order message>

<actual post order>

//end output

*/

#include<iostream>
#include<stack>

using std::cout;
using std::endl;
using std::stack;

//node structure

struct node {

int data;
node *left;
node *right;
node(int x): data(x), left(0), right(0) {}

};

void postOrder(node * root);

int main(){

//construct nodes 

node * n1 = new node(1); 
node * n2 = new node(2);
node * n3 = new node (3);
node * n4 = new node(4);
node * n5 = new node(5);
node * n6 = new node(6);

//create tree

n1->left = n2;
n1->right = n3;
n2->left = n4;
n2->right = n5;
n3->right = n6;


//make it fancy
cout << "\n    Binary Tree\n" << endl;
cout << "        " <<  n1->data << endl;
cout << "       / \\" << endl;
cout << "      " << n2->data << "   " << n3->data << endl;
cout << "     / \\   \\" << endl;
cout  <<"    " <<  n4->data << "   " << n5->data << "   " << n6->data << endl;
cout << "\n" << "  Post Order of Tree:\n " << endl;

//give em the goods
postOrder(n1);

//
cout << "\n" << endl;


return 0;

}//end main


void postOrder(node *root) {
  cout << "    ";
	// no root
	if (!root) return;
  
	stack<node *> tree;
  	
	tree.push(root);
  
	node * prev = 0;

	while (!tree.empty()) {
    
		node * curr = tree.top();
    		
		if (!prev || prev->left == curr || prev->right == curr) 		{
      			if (curr->left)
				//stack to the left if that way is possible
        			tree.push(curr->left);
      			else if (curr->right)
				//otherwise stack right
        			tree.push(curr->right);
    		} 
		else if (curr->left == prev) {
			
      			if (curr->right)
				//if the left has been traversed
				//stack right
        			tree.push(curr->right);
    		} 
			else {
				//else you're at the target, so output the data
      				cout << curr->data << " ";
				//move down the stack
      				tree.pop();
    			}
		
		//set up relationship for next iteration
    		prev = curr;
  		}
		
}//end postOrder
