heap_increase_key(Heap A, int i , int key){

	if(A[i] > key){
	//	throw error;
	}
	A[i] = key

	int p = parent(i) //index of parent of A[i]

	if(p >= 0 && p < A[i]){
	
		swap(A[p], A[i]);
	
	}

	i = p;

	p = parent(i);

	
		

}


heap_insert(Heap A, int key){

	A.size++;
	A[size-1] = 0;
	//size-1 == current largest index, since index begins at 0

	heap_increase_key(A, size-1, key);

}

//can't unsort a tree give just preorder and post order
//in order must !! be present

//heap sort O(2nlogn) insertion sort better for items under 30
// quick sort is better for sorts over thirty in size


// quick sort

// pick a pivot, far right or far left (Typically), random is fine

// reorganize with smaller items on left of pivot and larger ones on right

//then apply quick sort to left and right

quick_sort(){

	int array[] = { 2, 8, 7, 1, 3, 5, 6, 4};

	int size = 8;
	//pick pivot

	int pivot = array[size - 1];

	//step one 
	
	//2 8 7 1 3 5 6 4 

	//go from far left side of array (before pivot) looking for members larger than pivot, stopping when a member smaller than pivot is found,
	// then doing the same from the right and stopping when a number larger than the pivot is found. Then swap the two. 

	//step two

	//repeat the above until every number has ben accounted for

	//then swap last larger number than pivot and pivot to put
	//pivot in middle

	//best case == nlogn, worst case == n^2 (if sorted already)

	//Hoare's partition (pg.185 in algorithm text) is best method
	
}//end quick sort

//T(n) = T(O.1n) + T(0.9n) + O(n) 
// +  T(.09n) + T(.81n) + 0.9n + n
	

}

/*

lower boundary of comparison based sorting

1:2 decision tree

binary tree

each branch is a comparison 

the sorted result is in one of the leaves

structure has n! leaves, where n is number of elements being compared

binary tree with l levels, has at most 2^l leaves

n! is number of leaves, 2^l is max number of leaves, so n! <= 2^l

Chapter 8 ---- textbook reference ----------


radix sort --- sort by least significant digit and mvoe to most significant digit, sort has complexity of O(n)



stable sorting

for some sorting algorithm

~alg maintains the relative order of equal keys whenever there are two records R and S with the same key. If R appears before S before the sorting, then
if R still appears before S before the sorting, then this algorthm is STABLE.

radix sort is stable

heap is not stable

merge is stable

quick sort is unstable

bubble is stable

insertion is stable


if two numbers agree on the second digit, the proper relative orer is preserved
if two numbers agree on the first digit, stability will keep them in proper relative order




hash motivation: fast search, insertion, deletion for elements in symbol table

best case is O(lg(n)), we expect to achieve O(1) "constant time"

sorting: bast case O(nlgn) for comparison based sort

radix sort: based on keys O(n) test with aaray[i] = randomNumber * (2^31 - 1)

quick sort: test for both types of quick sort partitions (lomuto and hoare)

hash funnction involves two steps

1) hash function, transform key into index/table address
2) collision resolution. two or more different keys that map to the same address
 
two solutions for collisions: linked list, linear probe

hash is a trade off between time and space, if more time, linear search, if no
space they must all go in same address

hash uses are reasonable amount of memory and time

in particular, we can strike any balance by adjusting the table size, not by
rewriting code or choosing different algorithms

we can expect search, insertion, deletion operations in symbol table 
to be evaluated in constant time, dependent on the table size 

warning(!): hash is not panacea 

running time does depend on the length of key 

hash does not help sorting in symbol table (does not help selection)
but *does* help insertion into table

***hash functions***

request for hashing function ==> values in (0 to m-1), if table size is m

should be easy to compute

should approximate a random function-> for each input, each output should
be equally likely

hash function to make key for table of size m == random [0, 1) * m
can round down but not up

float # in [a, b) where a and b are integers && a < b 

for example, the keys are in range [2, 6)

to go from key in range of [2, 6) to [0, 1), just do [(key - 2)/4] * m for table
size == m

 
so.......go map a float from [a, b) for table size m is ((key-a)/(b-a) * m)



*****w-bit integer********


ex: w = 3

keys are 000, 010, 001, etc

(key/2^w) * m 

















*/



