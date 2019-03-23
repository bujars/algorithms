#include <cstdlib>
#include <iostream>
using namespace std;

/* HeapSort verse MergeSort vs InsertionSort.
 *
 * Heapsort's time complexity is Big-O(nlogn), but usally Theta(nlogn). We say Big-O because it works as a tree and goes down a path which can vary in length.
 * Again, Insertion Sort Average is Theta(n^2) which is worse than HeapSort.
 *
 * HeapSort and MergeSort are about the same so they are interchangable.
 *
 * Like MergeSort, HeapSort requires more than one function, in this case 3. But its additional space is not the same. See Propertieis. 
 *
 * */

/* HeapSort properities.
 * => 1 Note a heap is a different data structure. Its stored in an array but has some properites. It must be a complete tree, the root node is the largest element, all children elements are smaller than the parent.
 *
 * Time Complexity: Big-O/Theta(n).
 * Space Complexity: O(1)
 * Stable Sorting: False. Remmeber it always takes the first element first and places it at the end of the array. Duhhhh. Google and youll see the first link.
 * Online: No. It doesnt sort as it takes them in, infact its reverse. 
 * In-Place: Yes! No additional space was needed!
 *
 * */

	/* NOTE you may get a little confused. This doesnt make sure that the largest child is above. It just puts the index element in the smallest position possible. So when you shift children up, its very possible that they still defeat the heap property, but thats why in build heap we start from the last parent and work our way up.*/
	void heapify(int A[], size_t n, size_t index){
		size_t left = index*2+1;
		size_t right = left+1;
		size_t largest;
		if((left < n) && (A[index] < A[left])){
			largest = left;
		} else{
			largest = index;
		}
		if((right < n) && (A[largest] < A[right])){
				largest = right;
		}
		/* Now that the largest index is checked. */
		if(largest != index){ /* Make sure that we dont have same function. think of this as the "base case". */
			int temp = A[index];
			A[index] = A[largest];
			A[largest] = temp;
			heapify(A, n, largest);
		}
			
	}

	void buildHeap(int A[], size_t n){
		/* Start from the very last parent and work your way up, bringing the greater element up and up. */
		/*NOTE this has to be int iterator else it will be infinite loop.*/
		for(int i = (n)/2; i >= 0; i--){ 
			heapify(A, n, i); 
		}
		
	}

	void heapSortAlgorithm(int A[], size_t n){
		buildHeap(A, n); /*Create the inital heap because thats how heapsort worls*/
		/*for(size_t i = 0; i < n; i++){
			cout << A[i] << " _ ";
		}
		cout << endl << endl;
		cout << "stuck here" << endl;*/
		
		/* end before first index because last element will be in first posiiton, so no need to swap with self.*/
		for(size_t i = n-1; i > 0; i--){ /*You go backwards because we bring the first element to the last position, and swap first with last. and work our way until we have only the first two elements left and then swap where the first one will then be in the corect posiiton. */
			
			int temp = A[0];
			A[0] = A[i];
			A[i] = temp;
			/*cout << A[i] << endl;*/
			n--; /*Decrease the size because now we dont look at the last element once it is sorted. */
			heapify(A, n, 0); /* Note that now, we need to re-heapify*/
		}


	}



#if 0


	/* This is a recursive function. So we would say T(n) 
	 * Time Complexity: Big-O(logn)*/
	void heapify(int A[], size_t n, size_t index){ 
		size_t left = index*2+1; /* Theta(1) */
		size_t right = left+1; /* Theta(1) */
		size_t largest; /* Theta(1) */
		if((left < n) && (A[index] < A[left])){ /* Theta(1) */
			largest = left; /* Theta(1) */
		} else{ /* Theta(1) */
			largest = index; /* Theta(1) */
		}
		if((right < n) && (A[largest] < A[right])){ /* Theta(1) */
				largest = right; /* Theta(1) */
		}
		if(largest != index){  /* Theta(1) */
			int temp = A[index]; /* Theta(1) */
			A[index] = A[largest]; /* Theta(1) */
			A[largest] = temp; /* Theta(1) */
			heapify(A, n, largest); /* T(n/2) ==> Because we look only at one portion of the array. In fact this only continues to go down the path. */
		}			
	}
	/* T(n) = T(n/2) + Theta(1) ... WE can use master theorm
	 *
	 * n^(log 2 of 1) == 1 and f(n) = Theta(1)  1==1 so we use case 2, which is Theta(f(n)logn) == Theta(1*logn) ==> Theta(logn)....Although I may be inclined to say Theta, the correct notation is infact Big-O(logn) becuse we might have the first child smaller and terminate at the first call!
	 *
	 *  Thus Time complexity = Big-O(log n)
	 * */


	/*Time complexity ==> Big-O(nlogn)*/
	void buildHeap(int A[], size_t n){
		for(int i = (n)/2; i >= 0; i--){ /*Theta(n/2)*/
			heapify(A, n, i); /*Big-O(logn) ==> from above*/
		}
	}
	/* Total = Theta(n/2) or simply Theta(n) * Big-O(logn) ===> Big-O(nlogn).*/


	/* Big-O/Theta(nlogn) */
	void heapSortAlgorithm(int A[], size_t n){
		buildHeap(A, n); /*Big-O(nlogn)*/
		for(size_t i = n-1; i > 0; i--){ /*Theta(n-1)*/
			int temp = A[0];
			A[0] = A[i]; /* Theta(1) */
			A[i] = temp; /* Theta(1) */
			n--; /* Theta(1) */
			heapify(A, n, 0); /*Big-O(logn)*/
		}
	}
	/* Total: Big-O(nlogn) + Theta(n-1)*Big-O(logn) ===> 2*Big-O(nlogn) ===> Big-O(nlogn).
	 *
	 * Note in most cases its the worst case, which is why we say Big-O/Theta(nlogn) 
	 * 
	 * */
	
#endif

