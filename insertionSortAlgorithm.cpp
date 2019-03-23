#include <cstdlib>
using namespace std;

/* Precondition: None.
 * Postcondition: Array is sorted.
 *
 * See comments to understand what is going on, incase you forget.
 *
 * Time Complexity: Best Case sceneario: The array is pre-sorted so we don't have to go through the while loop and shift everything. Thus Theta-(n-1), just Theta(n).
 * Worst Case: THe array is reversely sorted, so we go through both loops. Thus n-1*n = Theta(n^2).
 * Average Case: Note in most cases, the array is not sorted, so it comes down to Theta(n^2) becasue it goes through both loops in most cases. */
void insertionSortAlgorithm(int A[], size_t n){
	/*Start from index 1 becasue base case is that an array of size 1 is already sorted. */
	for(size_t i = 1; i < n; i++){
		int key = A[i]; /*Store current value. */
		size_t j = i-1; /*Create iterator that will go through previous elements*/
		while(j >= 0 && A[j] > key){ /*While going through previous, and that our previous elemetns are greater than current*/
			A[j+1] = A[j]; /* "shift" over previous elements 1 position forward*/
			j--;
		}
		A[j+1] = key; /* Place key in the lastly shifted elemetns position*/
	}
}

#if 0
/* NOTE writing time complexities next to each line. */

void insertionSortAlgorithm(int A[], size_t n){
	for(size_t i = 1; i < n; i++){ /* Theta(n-1)*/
 		int key = A[i]; /* Theta(1)*/
		size_t j = i-1; /* Theta(1)*/
		while(j > 0 && A[j] > key){ /* Theta(n) ==> Varies in the umber of times it goes through. */
			A[j+1] = A[j]; /* Theta(1) */
			j--;
		}
		A[j+1] = key; /* Theta(1) */
	}
}

#endif

