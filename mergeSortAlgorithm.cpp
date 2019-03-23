#include <cstdlib>
#include <limits>
#include <iostream>
using namespace std;

/* NOTE the difference between mergeSortAlgorithm and insertionSortAlgorithm
 * 1. MergeSort Has 2 functions
 * 2. MergeSort has the same time complexity in all cases Theta(nlogn). Insertion Sort Average case is Theta(n^2)
 * 3. MergeSort time complexity is faster than insertionSort. nlogn< n^2
 * Sidenote: for smaller array sizes, insertionSort is better but we are disregarding this knowledge for now. 
*/

/* NOTE MergeSort Properties
 * 1. Time Complexity: Theta(nlogn)
 * 2. Space Complexity: The additional size we need to perform these operations Theta(n), because of L/R arrays in merge() 
 * 3. Stable Sorting: True. Duplicates remain in same order, this is becasue left porition is checked first.
 * 4. In-Place: False. We require additional arrays for Merge.
 * 5. Online: False, it doesn't sort as it takes in elements.*/



/* Precondition: A is assumed to have values less than max.
 * Postcondition: A within p and r is sorted. */
void merge(int A[], size_t n, size_t p, size_t q, size_t r){
	/*Compute left and right arrays, see notes. */
	size_t leftSize = q-p+2;  
	size_t rightSize = r-q+1; 
	int leftArray [leftSize]; /*Create the left side array including an extra element. +2 because when p is 0 its still one element */
	int rightArray [rightSize]; /*Create the right side array including an extra element. */
	
	/*Set the left and right array values accordingly from A.*/
	size_t leftIndex = 0;
	/*cout << "thus far" << endl;*/
	for(size_t i = p; i <= q; i++){
		leftArray[leftIndex] = A[i];
		leftIndex++;
	}
	size_t rightIndex = 0;
	for(size_t i = q+1; i <= r; i++){
		rightArray[rightIndex] = A[i];
		rightIndex++;
	}

	/*Set the last value to the maximum, which will terminate the ifstatements. Remember, we are assuming every value is smaller since we dont have infinitiy.*/
	leftArray[leftIndex] = std::numeric_limits<int>::max();
	rightArray[rightIndex] = std::numeric_limits<int>::max();
	/*cout << "even furthur" << endl;*/
	leftIndex = 0;
	rightIndex = 0;

	/*cout << "hm" << endl;*/
	/*move everything back into A. cases, both still have elements, one array ran out, or the other ran out.*/
	for(size_t i = p; i <= r; i++){
		if(leftIndex < leftSize && rightIndex < rightSize){ /* We can still compare both */
			if(leftArray[leftIndex] <= rightArray[rightIndex]){
				A[i] = leftArray[leftIndex];
				leftIndex++;
			} else { /* right is smaller */
				A[i] = rightArray[rightIndex];
				rightIndex++;
			}
		} else if(leftIndex < leftSize){ /*Right side is done.*/
			A[i] = leftArray[leftIndex];
			leftIndex++;
		}
		else if(rightIndex< rightSize){ /*Left size is done. */
			A[i] = rightArray[rightIndex];
			rightIndex++;
		}
	}
}



/* NOTE r = n-1
 * Precondition: p < r. Also, assuming that all values of A are smaller than the mex value an int can hold.
 * Note this is an underlying error but for the purposes of understanding the algorithm is not necessary.
 * Postcondition: Sorted array. */
void mergeSortAlgorithm(int A[], size_t n, size_t p, size_t r){
	if(p < r){ /*Keep dividing until our size is 1*/
		size_t q = (p+r)/2; /*Find midpoint.*/
		mergeSortAlgorithm(A, n, p, q); /* Divide left side.  NOTE you keep q because you will have to merge it back.*/
		mergeSortAlgorithm(A, n, q+1, r); /* Divide right side.*/
		/* cout << "Here in mergeSort " << endl; //error was above i had the wrong arguments. */
		merge(A, n, p, q, r); /* Merge the two arrays back using a separate function. */
	}
}

#if 0

/* NOTE for recursive functions, Time Complexity is always represented using a function (or unknown until we figure it out.)*/
/* Time complexity = Theta(nlogn)*/
void mergeSortAlgorithm(int A[], size_t n, size_t p, size_t r){ /*Let name this T(n)*/
	if(p < r){ /* Theta(1) */
		size_t q = (p+r)/2; /* Theta(1) */
		mergeSortAlgorithm(A, n, p, q); /* Note this is at least T(n/2) because we are dividing the input size by 2. The second part of it is Theta(n/2) from the merge function that is called every time. So T(n/2)+ Theta(n/2) (or just Theta(n)) */
		mergeSortAlgorithm(A, n, q+1, r); /*Same as above*/
		merge(A, n, p, q, r); /*This takes Theta(n) time as we will soon see.*/
	}
}
/* Total time: T(n) = 2(T(n/2)+Theta(n)) ==> 2T(n/2) + Theta(n).
 * We can use a recursion tree, or master theorem to show 2T(n/2).
 *
 * Using master theorem, log 2(b==> n/2) of 2(a ==> constant in from of T) == n^1 and our function f(n) (just Theta n which is secondardy operation) is also n^1.
 * Because n^1  = n^1, we can use case 2 of master theorm. which is Theta(f(n)logn) ==> Theta(nlogn) ==> Time complextiy. Note this is the same for all cases.
 *
 * */


/* Time complexity Total = Theta(n)*/
void merge(int A[], size_t n, size_t p, size_t q, size_t r){
	size_t leftSize = q-p+2;  /* Theta(1) */
	size_t rightSize = r-q+1; /* Theta(1) */
	int leftArray [leftSize]; /* Theta(1) ===> Note this is the additional allocated space. */
	int rightArray [rightSize]; /* Theta(1) ===> Note this is the additional allocated space. */

	size_t leftIndex = 0;/* Theta(1) */ 
	for(size_t i = p; i <= q; i++){ /*A bout Theta(n/2) */
		leftArray[leftIndex] = A[i];
		leftIndex++;
	}
	size_t rightIndex = 0; /* Theta(1) */
 	for(size_t i = q+1; i <= r; i++){ /* About Theta(n/2) */
		rightArray[rightIndex] = A[i];
		rightIndex++;
	}

	leftArray[leftIndex] = std::numeric_limits<int>::max(); /* Theta(1) */
	rightArray[rightIndex] = std::numeric_limits<int>::max(); /* Theta(1) */
	
	leftIndex = 0; /* Theta(1) */
	rightIndex = 0; /* Theta(1) */

	/* Theta(p-r) which is just input size n each time. */
	for(size_t i = p; i <= r; i++){ 
		if(leftIndex < leftSize && rightIndex < rightSize){
			if(leftArray[leftIndex] <= rightArray[rightIndex]){
				A[i] = leftArray[leftIndex];
				leftIndex++;
			} else { 
				A[i] = rightArray[rightIndex];
				rightIndex++;
			}
		} else if(leftIndex < leftSize){
			A[i] = leftArray[leftIndex];
			leftIndex++;
		}
		else if(rightIndex< rightSize){ 
			A[i] = rightArray[rightIndex];
			rightIndex++;
		}
	}
}

#endif

