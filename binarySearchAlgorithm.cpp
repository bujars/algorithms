#include <cstdlib>
using namespace std;

/* Precondition: The array must be sorted else there will be an error. The start index p is smaller than the end index r. (Start r as the size-1 to check all array).
 * Postcondiiton: Element X is either in or not in the array.
 * This works by spliting the array in half each time and checking if the value of x is either in the left or right.
 * A good real life example of this is flipping through a book when you want to find a page, you usually open in the middle then chunk out the next...etc
 *
 * Note p is the start index, r is the end index. 
 *
 * Time Complexity Big-O(log n). NOTE it is (log n), becasue we are going down one path of the tree and ignoring half of the tree each time we go down. 
 * Because logn < n, this solution is more optimal in terms of Time Complexity. */
bool binarySearchAlgorithm(int A[], size_t n, size_t p, size_t r, int x){
	if(p <= r){
		/*Calculate middle*/
		int mid = (p+r)/2;
		if(A[mid]==x){
			return true;
		}
		if(x < A[mid]){
			return binarySearchAlgorithm(A, n, p, mid-1, x); /*Search through left half*/
		} else{
			return binarySearchAlgorithm(A, n, mid+1, r, x); /*Search through right half*/
		}
	}
	return false;
}

/* Note I was originally going to write a method called is sorted to make a second version of binary search which checks if the passed in array is sorted. But if I was to check that each time in the alorithm it would make the size Big-O(n logn) */

bool isSorted(int A[], size_t n){
	if(n >= 1){
		if(n >= 2){
			int previousElement = A[0];
			size_t i = 1;
			while(i < n){
				if(previousElement > A[i]){
					return false;
				} else{ 
					previousElement = A[i];
					i++;
				}
			}
		}
		return true;
	}
	return false;
}


