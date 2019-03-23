#include <cstdlib>
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

	void heapify(int A[], size_t n, size_t index){
		if((index*2+1) < n){ /* make sure we aren't out of bounds. And that we at least have a left child. We can't have a right without a left. */
			size_t largest = index;
			if(A[index] < A[index*2+1]){
				largest = index*2+1;
			}
			if(index*2+2 < n){ /* make sure we have a right child.*/
				if(A[largest] < A[index*2+2]){
					largest = index*2+2;
				}
			}
			/* Now that the largest index is checked. */
			if(largest != index){ /* Make sure that we dont have same function. think of this as the "base case". */
				int temp = A[index];
				A[index] = A[largest];
				A[largest] = A[index];
				heapify(A, n, largest);
			}
			
		}
	}

	void buildHeap(int A[], size_t n){
		/* Start from the very last parent and work your way up, bringing the greater element up and up. */
		for(size_t i = n/2; i >= 0; i++){
			heapify(A, n, i); 
		}
		
	}
