/*
Title: sortComparison.cpp

Author: Chris Aggeles

email: aggeles@uga.edu

Purpose: to compare various sorting techniques and find the most efficient

Key Ideas: merge, radix, quick (l & h), bubble, and system sorts 

Sample I/O:  the program creates several integer arrays and then fills
them with random integers ranging from zero to 2^32-1. The program then runs a distinct array through a distinct sort and calculates the time taken (minus the
time taken to compute the time, of course) and reports that to the console.
Each sort has varying lengths, quicksort ended up being faster for me. I tried
several versions of a radix sort (there are two in the code, one commented out
that we worked on in class, but wouldn't pass the is ascending method for me,
and the other, less succesful method that is run in main(). That radix sort
runs in something like 400ms, which I know is about 10x what is to be hoped for
so if you could maybe return some feedback on what is wrong with the 
commented out radix sort, I'd be very grateful. I tested the bubbleSort with
smaller arrays, but have yet to run a full million just for time's sake.
Nevertheless, the code is functional and won't pose an issue during runtime.
The other sorts were very painless and ran consistently with no issues.

*/ 





#include <iostream>
#include <cstdlib> //RAND_MAX
#include <ctime> //clock
#include <algorithm> //sort
using namespace std;

void mergeSort(int *, int, int);

void quickSort_hoare(int *, int,  int);
void quickSort_lomuto(int *,int,  int);

int hoarePartition(int *, int, int);
int lomutoPartition(int *, int, int);
//void countSort(int *, int, int *, int);
void radixSort(int *, int);

void bubbleSort(int *, int);

void merge(int *,int, int , int );
//void radix(int *, int);

//for radix
int getMax(int[], int);

void countSort(int [], int, int);
//for main/verification
bool isAscending(int *, int);



int main(int argc, char *argv[]) {
void print(int *, int);
	//sizeof(int) == RAND_MAX
    // RAND_MAX = 2147483647;
    int SIZE = 1000000;
    int *arrQH = new int[SIZE]; //arrQH is the array for quick sort using Hoare's partition.
    int *arrQL = new int[SIZE]; //arrQL is the array for quick sort using Lomuto's partition.
    //int *arrB = new int[SIZE]; //arrB is the array for bubble sort
    int *arrS = new int[SIZE]; //System provide sorting library
    int *arrM = new int[SIZE]; //merge sort
    int *arrR = new int[SIZE]; //radix sort
	int *arrB = new int[SIZE]; //bubble sort
	//int *a = new int[SIZE];//used for alternate radix attempt
    for (int i = 0; i < SIZE; i++)
      arrB[i] = arrR[i] = arrM[i] = arrS[i] = arrQL[i] = arrQH[i] = rand();
        //fills each index with integer from 0 to RAND_MAX, or int capacity
	//should be relatively random sample from which to test sorting algorithms
	//size = 1 * 10 ^ 6 

	//easiest method of testing is clockcycles
	//so timing is set up to calculate some measure of resource dependence
	//for each sort

//Hoare sort 
   long start = clock();
	//first test is on Hoare's partition
    quickSort_hoare(arrQH, 0, SIZE);
	//get stop point for clock cycle measurement
    long end = clock();
	//check ordering in product of sort
    if (isAscending(arrQH, SIZE))
	//show the difference between starting and stopping points
	//this difference is the estimated time dependence for the program
	//A purely random sample would be more accurate, statistically speaking
	//but the estimate should be fairly close.
       	cout << "quick sort using Hoare's partition: " << (end - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;
    //	print(arrQH, SIZE);
	

//Lomuto sort


 start = clock();
	//first test is on Hoare's partition
    quickSort_lomuto(arrQL, 0, SIZE-1);
	//get stop point for clock cycle measurement
     end = clock();
	//check ordering in product of sort
    if (isAscending(arrQH, SIZE))
	//show the difference between starting and stopping points
	//this difference is the estimated time dependence for the program
	//A purely random sample would be more accurate, statistically speaking
	//but the estimate should be fairly close.
       	cout << "quick sort using Lomuto's partition: " << (end - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;
    //	print(arrQH, SIZE);	


//radix sort


 start = clock();
	//first test is on Hoare's partition
    radixSort(arrR, SIZE);
	//get stop point for clock cycle measurement
     end = clock();
	//check ordering in product of sort
    if (isAscending(arrR, SIZE))
	//show the difference between starting and stopping points
	//this difference is the estimated time dependence for the program
	//A purely random sample would be more accurate, statistically speaking
	//but the estimate should be fairly close.

                                                                                       	cout << "radix sort: " << (end - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;
    //	print(a, SIZE);




start = clock();
	//first test is on Hoare's partition
    bubbleSort(arrB, SIZE);
	//get stop point for clock cycle measurement
    end = clock();
	//check ordering in product of sort
    if (isAscending(arrB, SIZE))
	//show the difference between starting and stopping points
	//this difference is the estimated time dependence for the program
	//A purely random sample would be more accurate, statistically speaking
	//but the estimate should be fairly close.
       	cout << "bubble sort: " << (end - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;
    //	print(arrB, SIZE);





//merge sort


 start = clock();
	//first test is on Hoare's partition
    mergeSort(arrM, 0, SIZE);
	//get stop point for clock cycle measurement
     end = clock();
	//check ordering in product of sort
    if (isAscending(arrM, SIZE))
	//show the difference between starting and stopping points
	//this difference is the estimated time dependence for the program
	//A purely random sample would be more accurate, statistically speaking
	//but the estimate should be fairly close.
       	cout << "merge sort: " << (end - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;
    	//print(arrM, SIZE);

/*
//test radix
 start = clock();
	//first test is on Hoare's partition
    radix(a, SIZE);
	//get stop point for clock cycle measurement
     end = clock();
	//check ordering in product of sort
    if (isAscending(a, SIZE))
	//show the difference between starting and stopping points
	//this difference is the estimated time dependence for the program
	//A purely random sample would be more accurate, statistically speaking
	//but the estimate should be fairly close.
       	cout << "merge sort: " << (end - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;
    	//print(arrM, SIZE);
  */      
//system sort

 
  start = clock();
   std::sort(arrS, arrS + SIZE); //sort provided by c++
   end = clock();
   cout << "system provided sort: " << (end - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;
   //print(arrS, SIZE);
}

/*
void radix(int * a, int size){
//add FF to shift int 8 bits

 		
	for(int shift = 0; shift < 32;shift += 8){
int * b = new int[size];	
                     //partially sorted results go in b
                     //sort 8 bit tuple after shifting bits +8 to operate
                     //on next 8 bit grouping
                   
		//data moves from a to b in 8 bit packets
                                                                                          //then put back in a after b fills up with rest of a (unsorted)
                                                                                         if (shift == 0 || shift == 16) countSort(a, size, b, shift);
                                                                                         else countSort(b, size, a, shift);
	delete [] b;
        }                                                                                                                                                            
	
}
*/
bool isAscending(int * array, int size){

	bool isAscending = true;

	//compensate for last comparison by subtracting one
	for(int i = 0; i < size-1; i++){


		if(array[i] > array[i+1]) isAscending = false;

	}
	return isAscending;
}

void print(int * array, int size){

	for(int i = 0; i < size; i++){

	cout << array[i] << " ";

	}

}

void quickSort_lomuto(int list[], int beg, int end){
        
	 if(beg < end){

        int mid = lomutoPartition( list, beg, end );

        quickSort_lomuto( list, beg, mid-1 );
        
	quickSort_lomuto( list, mid+1, end );

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

void quickSort_hoare(int list[],int beg,int end) {


    if (end-beg<2) return;

    int mid = hoarePartition(list,beg,end);

    quickSort_hoare(list,beg,mid);
    quickSort_hoare(list,mid,end);
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



void mergeSort(int *a, int low, int high)

{

    int mid;

    if (low < high)

    {

        mid=(low+high)/2;

        mergeSort(a,low,mid);

        mergeSort(a,mid+1,high);

        merge(a,low,high,mid);

    }

    return;

}

void merge(int *initArray, int min, int max, int mid)

{

    int i, midIndex, counter, tempArray[1000000];

    	i = min;

	counter = min;
	midIndex = mid + 1;

    while (i <= mid && midIndex <= max)

    {

        if (initArray[i] < initArray[midIndex])

        {
		tempArray[counter] = initArray[i];
		counter++;
		i++;

        }

        else

        {
		tempArray[counter] = initArray[midIndex];
		counter++;
		midIndex++;
	}

    }

    while (i <= mid)

    {

        tempArray[counter] = initArray[i];
	counter++;
	i++;

    }

    while (midIndex <= max)

    {
	tempArray[counter] = initArray[midIndex];
	counter++;
	midIndex++;

    }

    for (i = min; i < counter; i++)
	{
        initArray[i] = tempArray[i];
	}
}

//used in radixSort
int greatest(int arr[], int size)

{

    int max = arr[0];

    for (int i = 1; i < size; i++)

        if (arr[i] > max)

            max = arr[i];

    return max;

}
/*
void countSort(int * a, int size, int * b, int shift){
        //0x100 is hexadecimal(base 16) representation of 256
                //1 * 16^2 = 256      255 = 0xFF 256 = 0x100 
                        int * c = new int[256];
			int tuple;//8 bit correspondent to chunk of 'a' being examined
                                        for(int i = 0; i < size; i++){
                                                        //bit operation is way faster than modulo or division
                                                                        //useful here because modulo is being done with power of 2
                                                                                        tuple = (a[i] >> shift) & 0xFF;
                                                                                                        //anding with 255 gives same
                                                                                                                        //result as modulo (%) 256
                                                                                                                                        //if % 32 was desired, 0x001F would be used instead of 0xFF
                                                                                                                                                        c[tuple]++;
        
        
                                                                                                                                                                }//end for
                                                                                                                                                                        for(int j = 1; j < 0x100 ; j++){
        
                                                                                                                                                                                        c[j] = c[j-1] + c[j];
                                                                                                                                                                                                }
                                                                                                                                                                                                        for(int i = size-1; i > 0; i--){
        
                                                                                                                                                                                                                        tuple = (a[i] >> shift) && 0xFF;
                                                                                                                                                                                                                                        b[c[tuple-1]] = a[i];
                                                                                                                                                                                                                                                        c[tuple]--;
                                                                                                                                                                                                                                                                        //that's it!
        
                                                                                                                                                                                                                                                                                }
        
        
                                       delete [] c;                                                                                                                                                                                                                                        }  
//used in radixSort

*/
void countSort(int arr[], int n, int exp)

{

    int output[n];

    int i, count[10] = {0};

    for (i = 0; i < n; i++)

        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)

        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--)

    {

        output[count[(arr[i] / exp) % 10] - 1] = arr[i];

        count[(arr[i] / exp) % 10]--;

    }

    for (i = 0; i < n; i++)

        arr[i] = output[i];

}
  

void radixSort(int arr[], int size)

{

    int max = greatest(arr, size);

    for (int exp = 1; max / exp > 0; exp *= 10)

        countSort(arr, size, exp);

}


void bubbleSort(int *arrB, int size)
{
    int temp;
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size - i - 1; j++)
            if(arrB[j] > arrB[j + 1])
            {
                temp = arrB[j];
                arrB[j] = arrB[j + 1];
                arrB[j + 1] = temp;
            }
}

         


