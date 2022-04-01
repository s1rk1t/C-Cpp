/*
Title: zigzag
Author: Chris Aggeles
email: aggeles@uga.edu

Purpose: to print out a binary tree's nodes in zigzag order, meaning
that the printing will be done first from leftmost node to the rightmost node,
then the print out will continue on the next level down from the leftmost to 
the rightmost, back and forth until all levels are displayed.

Key Points: Using a stack and queue seems like a good strategy, as one
can push to a stack to print out one direction, then push to a queue to print
out the other, assuming that one prints them out front->back/top->bottom, but
given that the method described by the homework is of a vector of vectors, 
the most logical approach would be to create a vector of int data from the root,
then for each successive level, create another vector, and insert or push_back
in alternating fashion the order that one prints them out until the tree is 
empty. 

Sample I/O: the program will print out a zigzag traversal of a binary tree.
The tree will be printed out first to show its structure for reference.
*/

#include<vector>
#include<iterator>
#include<iostream>
#include<string>
#include<cmath>

using std::string;
using std::cout;
using std::vector;
using std::iterator;
using std::endl;


struct treeNode{

	int val;

	treeNode * left;
	treeNode * right;
	treeNode(int x) : val(x), left(NULL), right(NULL) {}
};//end struct


int getHeight(treeNode *); 

void printZigZag(vector< vector<int> >);

vector< vector<int> > zigzag(treeNode *);



int main(){

int maxNodes = 7;

int levels = 3;

vector< vector<int> > ziggy(levels); 
//declare nodes
treeNode * n1 = new treeNode(2);


treeNode *n2 = new treeNode(3);
treeNode *root = new treeNode(1);

treeNode *n3 = new treeNode(4);

treeNode *n4 = new treeNode(5);


root->right = n2;
root->left = n1;

n1->left = n3;
n1->right = n4;

n2->right = 0;
n2->left = 0;
//get the vector
ziggy = zigzag(root);

//show em what you got!
cout <<"\n1st Binary Tree\n\n" << endl;
cout <<"    1   " << endl;
cout <<"   / \\  " << endl;
cout <<"  2   3 " << endl;
cout <<" / \\   " << endl;
cout <<"4   5    "<< endl;

cout << "\nFirst Zig Zag Traversal\n";

printZigZag(ziggy);

treeNode * n5 = new treeNode(2);


treeNode *n6 = new treeNode(3);
treeNode *root2 = new treeNode(1);

treeNode *n7 = new treeNode(4);

treeNode *n8 = new treeNode(5);

root2->right = n6;
root2->left = n5;
n5->left = n7;
n6->right = n8;

cout <<"\n2nd Binary Tree\n\n" << endl;
cout <<"    1   " << endl;
cout <<"   / \\  " << endl;
cout <<"  2   3 " << endl;
cout <<" /     \\ " << endl;
cout <<"4       5 "<< endl;


//build second tree


cout << "\n2nd Zig Zag Traversal" << endl;

ziggy = zigzag(root2);

//show em the goods
printZigZag(ziggy);
cout << "" <<endl;
}

void printZigZag(vector<vector<int> > ziggy){
	cout <<""<<endl;

	cout << "[";
	int max = ziggy.size();
	int index = 0;
		
	while(index < max){
	cout << "[";
	 for(int i = 0; i < ziggy[index].size(); i++){
		
		cout << ziggy[index][i] << " ";
	}
	
	index++;
	cout << "]";
	}
	cout << "]";
	cout << "" << endl;
}




vector<vector<int> > zigzag(treeNode * root){

	int index = 0;
	
	vector<vector<int> > result;
	
	while(index < getHeight(root)){

	if(index == 0){
		
		vector<int> first;
		first.insert(first.begin(), root->val);
		result.insert(result.begin(), first);
	
		index++;
	} 
	
	//second tier
	else if(index == 1){
	
	int r, l;	
	if(root->right) r = root->right->val;
	
	if(root->left) l = root->left->val;
		
	vector<int> second;
	
	if(r != 0) second.push_back(r);
	if(l != 0) second.push_back(l);

	result.insert(result.begin()+index, second);
	
	index++;
		}//end else
	
	//third tier
	else if(index == 2){
	
	vector<int> third;
	


	int n1R = 0;
	int n1L = 0;
	int n2R = 0;
	int n2L = 0;
	int b = 0;
		if(root->right->right) n2R = root->right->right->val;
		if(root->right->left) n2L = root->right->left->val;
		if(root->left->right) n1R = root->left->right->val;
		if(root->left->left) n1L = root->left->left->val;
		//cout << n1L << " " << n1R << " " << n2L << " " << n2R;	
		
		if(n1L != 0) third.insert(third.begin()+ b++, n1L);
		if(n1R != 0) third.insert(third.begin()+ b++, n1R);
		if(n2L != 0) third.insert(third.begin()+ b++, n2L);
		if(n2R != 0) third.insert(third.begin()+ b, n2R);

		result.insert(result.begin()+index, third);

		index++;	
		}//end else



	}//end while
	return result;
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



  
