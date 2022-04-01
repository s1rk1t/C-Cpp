/*
Title: buildBST
Author: Chris Aggeles
email: aggeles@uga.edu

Purpose: to build the shortest BST possible given an array of unique
values

Key Ideas: Using recursion seemed lie the logic choice. Essentially, I 
chose the mid point of the array as the root node, then divided the rest of
the array into two arrays, one contains what is to the right of the root
the other what is to the left. I then ran the function on both of those
arrays, attaching the results to the right and left of the root (if possible).

Sample I/O: program will output the inital integer array that is to be
made into a binary tree. It will then output an inorder traversal
of that binary tree, as well as listing the tree's height.

*/
#include<iostream>
#include<vector>

using std::vector;
using std::cout;
using std::endl;


struct treeNode {
      int val;
      treeNode *left;
      treeNode *right;
      treeNode(int x) : val(x), left(NULL), right(NULL) {}
};

treeNode * buildTree(vector<int>);

void inorder(treeNode *);

int getHeight(treeNode * root);

int main(){

int array[7] = {1,2,3,4,5,6,7};

vector<int> v(array, array + sizeof(array) / sizeof(int) );


treeNode * root = new treeNode(0);
root = buildTree(v);

cout << "\nInitial array: {1,2,3,4,5,6,7}\n" << endl;

cout << "In order traversal of tree built from array: " << endl;

cout << "(Values should be the same!)\n"<< endl;

inorder(root);
int height;
height = getHeight(root);
cout << "\nHeight = " << height << endl;

}
int getHeight(treeNode * root){
        int l, r;

        if(root == NULL) {

        return 0;

        }
        else{
         l = getHeight(root->left);
         r = getHeight(root->right);
        }
        if(l > r) return l+1;
        else return r+1;
}



treeNode * buildTree(vector<int> nodes){
		

	int size = nodes.size();
	
	if(size == 1) {

	treeNode * leaf = new treeNode(nodes[0]);
	return leaf;

	}

	vector<int> left;
	vector<int> right;

	//determine mid point in array
	int mid = size/2;
		
	treeNode * node = new treeNode(nodes[mid]);
	
	
	
	//if there are at least three values
	if(size >= 3){	
	//isolate values to the left of the mid point in array 
	for(int j = 0; j < mid; j++){

	//go from array[0] to mid point (exclusive)
	left.push_back(nodes[j]);
	
	} //end for

	//isolate values to right of node in array
	for(int k = 1; k < size-mid; k++){
	
	//start array from point after midpoint, cont til end
	right.push_back(nodes[mid+k]);

	}//end for

	node->right = buildTree(right);
	node->left = buildTree(left);
	}//end if (i >= 3)
	
	//if there are two elements make the larger one branch to the right 
	//and the smaller one the parent node
	else if(size == 2){

	treeNode * n1 = new treeNode(nodes[0]);

	node->left = n1;
	
	}
	
	return node;

}

void inorder(treeNode * root)
{
	if(root){ 
       inorder(root->left);
       cout << root->val << " ";
       inorder(root->right);
    	}

}
