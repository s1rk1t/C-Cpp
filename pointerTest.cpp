#include<iostream>
#include<cstdlib>

using namespace std;

void printArray(int *);


int main(){

int * array = {1, 2, 3, 4, 5, 6, 7};

printArray(array);

}


printArray(int * array){

	for(int i = 0; i < 7; i++){

		cout << *(array+i) << " ";

	]

}
