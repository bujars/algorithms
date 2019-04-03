
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
	/* This index ^ just keeps track of the values smaller than our last/pivot element. */
	
	
	for(int i = p; i < r; i++){ /*Because r has our last index and we want to stop right before it, which is just  n-2.*/
		if(A[i] <= lastElement){ /*Only when we find a vlaue smaller than last, do we swap and incremt the index.*/
			/*smallerIndex++;*/
			int temp = A[i];
			A[i] =A[smallerIndex];
			A[smallerIndex] = temp;
			smallerIndex++;
		}
	} /* swap the pivot element with the location where all its values before are less than and all the values above are greater than. */
	A[r] = A[smallerIndex]; /* Note because we started small at p and not p-1 and we incremented the index at the end, here we will have the right index and no need to do smallerIndex+1. */
	A[smallerIndex] = lastElement;
	return smallerIndex; 

}

void quickSortAlgorithm(int A[], size_t n, int p, int r){
	if(p < r){
		int q = partition(A, n, p, r); /* Here we will keep track of the pivot element, which again is in between the  other elements. */
		quickSortAlgorithm(A, n, p , q-1); /* We recurisvely keep finding pivots before */
		quickSortAlgorithm(A, n, q+1, r); /* and after */
	}
}

#if 0

/* Time Complexity */
int partition(int A[], size_t n, int p, int r){ /* Theta (n)*/
	int lastElement = A[r]; /* Theta(1) */
	int smallerIndex = 0; /* Theta(1) */ 
	for(int i = 0; i < r; i++){ /* Theta (n-1) ==> Theta(n). Always goes through the size of the array...its a for loop. */
		if(A[i] < lastElement){
			int temp = A[i]; /* Theta(n) */
			A[i] =A[smallerIndex]; /* Theta(n) */
			A[smallerIndex] = temp; /* Theta(n) */
			smallerIndex++; /* Theta(n) */
		}
	}
	A[r] = A[smallerIndex]; /* Theta(n) */
	A[smallerIndex] = lastElement; /* Theta(n) */
	return smallerIndex; 
}



void quickSortAlgorithm(int A[], size_t n, int p, int r){ /* T(n) ==> Because its a recurive function*/
	if(p < r){ /* Theta(n) */
		int q = partition(A, n, p, r); /* Theta(n) ==> As seen above, we go through the elements.*/
		
		/* NOTE: Depending on the array, here we have two cases. 
		 * The first case is that our pivot is in the middle of the array. 
		 * If so we continue to divide the array in half or T(n/2) ==> 
		 * which comes out to be Theta(nlogn) ==> similar to merge sort. 
		 * But, lets say the pivot is always the last/first element in the array (worst case possible), 
		 * then our T(n-1) ==> which we see will come out to Theta(n^2).
		 * Thus, time complexity all depends on the pivot, but is on average Theta(nlogn)*/
		quickSortAlgorithm(A, n, p , q-1); 
		quickSortAlgorithm(A, n, q+1, r);
	}
}



#endif
