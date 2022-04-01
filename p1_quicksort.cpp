/*
Title: quicksort.cpp
Author: Chris Aggeles
email: aggeles@uga.edu

Purpose: learn to implement quick sort using hoare's and lomuto's partitions

Key Ideas: Position of pivot (front or back)

Sample I/O: The program will output the contents of two arrays, then perform
sorts on those arrays and display the results.

*/



#include<iostream>

using std::cout;
using std::endl;

//function definitions

void printList(int[]);

void lomutoQuickSort(int[], int, int);
int lomutoPartition(int[], int, int);

void hoareQuickSort(int[], int, int);
int hoarePartition(int[], int, int);


int main(){
	int length = 15;
	int startingIndex = 0;

	int hList[] = {1,4,2,5,8,3,6,9,34,26,47,21,43,91,14};

	cout << "\nBefore sorting\n" << endl;

	printList(hList);

	hoareQuickSort(hList, startingIndex, length);

	cout << "\n\nAfter sorting using Hoare's partition\n" << endl;

	printList(hList);

	cout << "\n" << endl;

	int lList[] = {1,4,7,2,4,90,54,76,25,34,21,65,35,8,2,56};

	cout << "Before sorting:\n" << endl;

	printList(lList);

	startingIndex = 0;

	length = 16;

	lomutoQuickSort(lList, startingIndex, length-1);

	cout << "\n\nAfter sorting using Lomuto's partition\n"<<endl;

	printList(lList);

	cout << "\n"<<endl;

	return 0;

}
void printList(int list[]){

	 
	
	int i = 0;
	
	while(list[i]){

	cout << list[i] << " ";
	i++;
	}

}




void hoareQuickSort(int list[],int beg,int end) {
    
    
    if (end-beg<2) return;
    
    int mid = hoarePartition(list,beg,end);
    
    hoareQuickSort(list,beg,mid);
    hoareQuickSort(list,mid,end);
}

int hoarePartition (int list[],int beg, int end) {
    
	int a = list[beg];
	int b = beg-1;
	int c = end;
    
	while (true) {
        do  c--; while (list[c] > a);
        do  b++; while (list[b] < a);
        if  (b < c){ 
            //swap
		int temp = list[b];
		list[b] = list[c];
		list[c] = temp;
		}
        else 
            return c + 1;
    }
}

void lomutoQuickSort(int list[],int beg,int end){
    	 if(beg < end){

 	int mid = lomutoPartition(list,beg,end);
    	
	lomutoQuickSort(list,beg,mid-1);
    	lomutoQuickSort(list,mid+1,end);
	
	}
}


int lomutoPartition(int list[], int beg, int end){
   
	int a, b, pivot, temp;

    pivot = list[end];
    a = beg-1;

    for(b = beg; b <= end-1; b++) {
        if(list[b] <= pivot) {
		a++;
            	temp = list[b];
            	list[b] = list[a];
            	list[a] = temp;
		
        }
    }

    temp = list[a+1];
    list[a+1] = list[end];
    list[end] = temp;

    return a+1;

}
