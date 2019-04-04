#include <cstdlib>
#include <cassert>
#include <iostream>

/* Counting Sort
 *
 * Unlike every previous sorting alogrithm that we have this seen, counting sort is different. Counting sort is not a comparision algorithm. 
 * But because counting sort is not a comparision algorithm, it comes with its limitations.
 *
 * Limitations:
 * All elements in the array of n must range from 0 to K (K being the largest possible number Note, the value of K must be known/figured out).
 * These values are important because they represent the indices in the array that we create to temporarly hold the count of each value. 
 *
 * Properities:
 * Stable Sorting: Yes (Our arrays count foward, but then place elements in backwards, maining the original position of duplicates).
 * In-Place: No! Far from it! We use two different arrays for input, one with original, the second is what we return.
 * Online: No. Goes through a whole process.
 * Time-Complexity: Theta(n+k) n is the size of the orignal array and k being the size of the temporary array that we create. 
 * Space-Complexity: Theta(n+k) Because we use two additional arrays in the process, one of size n, the other of size k.
 * One function. (Two if max isn't given and if we want to find it separeratly).
 *
 * Comparison to other Sorts: 
 * Because counting sort doesn't compare, it has a time complexity less than Theta(nlogn). 
 * Comparison sort is not divide-and-conquer like mergeSort or quickSort. 
 *
 *  
 * */

/* NOTE, because of our restriction from 0 to k, we can compare starting from 0 instead of INTEGER.MIN */
int maxVal(int A[], size_t n){
	int max = 0;
	for(size_t i = 0; i < n; i++){
		if(A[i]>max){
			max = A[i];
		}
	}
	return max;
}





/*Note */
void countingSortAlgorithm(int A[], int B[], size_t n){
	int max = (maxVal(A, n)) + 1; /*Must add one because our max is our max index.*/
	int C[max];
	for(size_t i = 0; i < max; i++){
		C[i] = 0; /* Initalize all values to 0. */
	}
	for(size_t i = 0; i < n; i++){
		B[i] = 0; /* Incase B has some garbage values. */ 
	}
	for(size_t i = 0; i < n; i++){ /*Sum up the number of elements in A that align with the index of C*/
		C[A[i]] = C[A[i]] + 1;
	}

	for(size_t i = 1; i < max; i++){
		C[i] = C[i] + C[i-1]; /*Cumulate the sum so that we know which indexes to refer to when we backtrack. Because say C[i] = 2, it means place the element in B[1]. */
	}
	for(int i = n-1; i >= 0; i--){
		
		B[C[A[i]]-1] = A[i]; /*NOTE it's minus one because in the psudeo we start B from 1. thats why when we cummulate the sum, at 0 we have 1 not 0! Duh!*/
		/*Here we find the appropriate index of B and store its value of A. We backtrack to keep stability, and because we need to decrement our sum of C, which tells us how many elements to insert of a particular value. */
		C[A[i]] = C[A[i]] - 1;
	}

}


#if 0

/* Time Complexity */

/* Theta(n) */
int maxVal(int A[], size_t n){
	int max = 0; /* Theta(1) */
	for(size_t i = 0; i < n; i++){ /* Theta(n) */
		if(A[i]>max){ /* Theta(1) */
			max = A[i]; /* Theta(1) */
		}
	}
	return max;
}





/* Total = 3Theta(n) + 2Theta(k) ==> Theta(n+k) */
void countingSortAlgorithm(int A[], int B[], size_t n){
	int max = (maxVal(A, n)) + 1; /*Must add one because our max is our max index.*/
	int C[max]; /* Theta(1) */
	for(size_t i = 0; i < max; i++){ /* Theta(k) */
		C[i] = 0; /* Theta(1) */
	}
	for(size_t i = 0; i < n; i++){ /* Theta(n) */
		B[i] = 0; /* Theta(1) */
	}
	for(size_t i = 0; i < n; i++){ /* Theta(n) */
		C[A[i]] = C[A[i]] + 1; /* Theta(1) */
	}

	for(size_t i = 1; i < max; i++){ /* Theta(k) */		
		C[i] = C[i] + C[i-1]; /* Theta(1) */
	}
	for(int i = n-1; i >= 0; i--){ /* Theta(n) */
		B[C[A[i]]-1] = A[i]; /* Theta(1) */
		C[A[i]] = C[A[i]] - 1; /* Theta(1) */
	}

}

#endif



