/*
Title: radixSort.cpp

Author: Chris Aggeles
email: aggeles@uga.edu

Purpose: to do a radix sort on an array of strings to sort them by lsd

Key Ideas: unfortunately, I was not able to get the code to work. 
I had several versions, many of which compiled, but none of which actually performed the correct sort. I feel like this version is very close to being correct,
but I don't understand enough about structs, vectors, and cpp in general 
to figure out what I am doing wrong. I spent over twenty hours on this homework
and although I am happy that I got done what I got done, I am very frustrated
by the fact that I was unable to figure out this last problem. It certainly
wasn't from a lack of trying. I apologize if this seems like a rant, but I have 
spent every free moment for the last several days trying to get these programs
to work properly, and now I am faced with a lackluster grade even after all
of that effort.


Sample I/O: n/a
*/





#include<string>
#include<iostream>
#include<vector>
#include<cstring>
#include<queue>

using std::strcmp;
using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::queue;

struct bucket{

	char ref;
	queue<string> box;
	bucket(char x) : ref(x){}
};


vector<string> radixSort(vector<string>, vector<bucket>, int);

vector<bucket> makeBuckets(int, vector<char>);

void printSortedArray(vector<string>);



int main(){

const string array[] = {"cow", "dog", "sea", "rug", "row", "mob", "tab", "bar", "ear", "tar", "dig", "big", "tea", "now", "fox"};

vector<string> v(array, array+15);


int alphabetLength = 26;



char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

vector<char> c(alphabet, alphabet+26);



vector<bucket> b = makeBuckets(alphabetLength, c);

//start at lsd (index == 2) and run recursively until sorted
v = radixSort(v, b, 2);

//show em the goods
printSortedArray(v);


return 0;

}

vector<bucket> makeBuckets(int size, vector<char> v){

	vector<bucket> b;

	for(int i = 0; i < size; i++){

		bucket x = new bucket(v[i]);
		b.insert(x);

	}

}//end makeBuckets

vector<string> radixSort(vector<string> v, vector<bucket> b, int n){

	if(n < 0) return v;


int arraySize = v.size();


	for(int j = 0; j < arraySize; j++){


		for(int i = 0; i < 26; i++){

			if(b[i].ref == v[j][n]){
			
				b[i].box.push(v[j]);	
			}//end if
		}//end for i 
	}//end for j

	int index = 0; 

	for(int k = 0; k < 26; k++){

		if(!(b[k].box.empty())){

		while(!(b[k].box.empty())){
			//fill up the array with the newly sorted queues
			v[index] = b[k].box.front();
			b[k].box.pop();
			index++;	
				}//end while !empty
			}//end if !empty
		}//end for k

	v = radixSort(v, b, n-1);

	return v;

	
}//end radix sort



void printSortedArray(vector<string> v){

	cout << "\nSorted Array:\n " << endl;

	int size = v.size();

	for(int i = 0; i < size; i++){

		cout << v[i] << " ";

	}
	cout << "" << endl;
}


