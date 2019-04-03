
/* QuickSort Algorithm is a sorting algorithm which paritions an array, and makes sure that all elements before the partition are less than/equal to and that all elements after the parition are greater than/equal to.
 *
 * Comparing to other Algorithms. 
 * Like MergeSort, QuickSort is a Divide-and-Conquer sorting Algorithm.
 * Like Heap,Merge,Insertion/Sort ==> QuickSort is what is known as a comparison based algorithm. Meaning that we compare a value to other elements. 
 * Because of this, and as we will see in the time complexitiy of the algorithm, these algorithms must make at least nlogn comparisions (which is why we usually see a run time of Theta(nlogn), which we will also see here).
 *
 * Properities: 
 * QuickSort has two functions: Recursinve QuickSortAlgorithm and Parition
 * Time Complexity: Best Case/Average Case: Theta(nlogn)  Worst Case Theta(n^2) ==> This happens when the array is already sorted/reversely sorted because the piviot will always be one element, the last element. For the best/average case, our piviot element is roughly in the middle. 
 * Space Complexity: Theta(n) ==> This is because we use n variables to store the parition values, or n of q. 
 * In-Place ==> True! Although we do have Theta(n) space, we are still using the same array! 
 * Online ==> No. It doesn't sort as it takes inputs in.
 * Stable Sorting: No [10, 80, 80, 20] ==> The first 80 will be swapped with 20 and therefor case closed...Unless its less than or equal, then it will swap again...(According to notes no.)
 * 
*/

int partition(int A[], size_t n, int p, int r){
	int lastElement = A[r]; /*Remember r is our index.*/
	int smallerIndex = p; /*Supposed to start 1 before, but in this case, we start from index 1 in the loop and always use our first value as 0. */
	for(int i = p; i < r; i++){ /*Because r has our last index and we want to stop right before it, which is just  n-2.*/
		if(A[i] <= lastElement){
			/*smallerIndex++;*/
			int temp = A[i];
			A[i] =A[smallerIndex];
			A[smallerIndex] = temp;
			smallerIndex++;
		}
	}
	A[r] = A[smallerIndex];
	A[smallerIndex] = lastElement;
	return smallerIndex; 

}

void quickSortAlgorithm(int A[], size_t n, int p, int r){
	if(p < r){
		int q = partition(A, n, p, r);
		quickSortAlgorithm(A, n, p , q-1);
		quickSortAlgorithm(A, n, q+1, r);
	}
}

#if 0
int partition(int A[], size_t n, int p, int r){
	int lastElement = A[r]; /*Remember r is our index.*/
	int smallerIndex = 0; /*Supposed to start 1 before, but in this case, we start from index 1 in the loop and always use our first value as 0. */
	for(int i = 0; i < r-1; i++){ /*Because r has our last index, which is just n-1. So n-2.*/
		if(A[i] < lastElement){
			int temp = A[i];
			A[i] =A[smallerIndex];
			A[smallerIndex] = temp;
			smallerIndex++;
		}
	}
	A[r] = A[smallerIndex];
	A[smallerIndex] = lastElement;
	return smallerIndex; 
}
#endif
