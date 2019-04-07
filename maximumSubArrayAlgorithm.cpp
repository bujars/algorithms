#include <cstdlib>
#include <iostream>
#include <limits.h>


/* This Algorithm is taking concepts that we learned from InsertionSort and MergeSort to apply to other problems unrelated to sorting.
 *
 * The Maximum Sub Array Algorithm is a problem of finding an array which composes of elements that when summed together give the maximum value. The array can be however many elements and located anywhere in the array, not just left to right.
 *
 * This problem works similar to Merge Sort where we divide the algorithm to check the left side, the right side, and the middle.
 * We recursively go thorugh each side, in which the conquer portion consists of combing sums starting from the middle of the sub array and working our way out.
 * The combine portion is returning te indicies and maximum sum.
 *
 * Break Down:
 * Time Complexity: Theta(nlogn)
 * Space Complexity: NOT SURE. CANT FIND ANSWER. Would say (unintelligently) Theta(1) ? Because we pass around indices? Or Theta(n) lie quicksort where we keep track of our indices... Maybe that sounds better since we do keep track of sums, and 2 other indices each time. 
 * ..........So lets assume Theta(n) ............
 *
 * */

#if 0
// A utility funtion to find maximum of two integers 
int max(int a, int b) { return (a > b)? a : b; } 
   
// A utility funtion to find maximum of three integers 
int max(int a, int b, int c) { return max(max(a, b), c); } 
     




/*As you will see notes below, I get rid of indice considerations in this code. THough its very cruical to understnad that those indices are important beause we want the sub  array. An alternative to how I would've solved it would be storing the values in mini arrays. */
int maxCrossingAlgorithm(int A[], size_t n, int low, int mid, int high){
	int leftSum = INT_MIN;
	int rightSum = INT_MIN;
	int sum = 0;
	for(int i = mid; i >= low; i--){
		sum=+A[i];
		if(sum > leftSum){
			leftSum = sum;
		}
	}
	sum = 0;
	for(int i = mid+1; i <=high; i++){
		sum+=A[i];
		if(sum > rightSum){
			rightSum = sum;
		}
	}
	return leftSum + rightSum;

}







/* NOTE that low and high are passed by reference, as we will see we need to 
 * save the indicies in the subarrays to send back the array itself.*/
/* NOTE NOTE ^ I got rid of it. See notes after mid.*/
/* This only returns the sum. Not the indices. */

int maximumSubArrayAlgorithm(int A[], size_t n, int low, int high){
	if(low == high){
		/*low, high stay the same. Just return the one element because its the only one its the max...*/
		return A[low];
	}
	int mid = (low+high)/2;
	/* I didn't think too plan ahead to figure out how the parameters low and high would actually be saved...
	 * So I am using geeks for geeks method, where they don't save the indices. */
	/*int leftSum = maximumSubArrayAlgorithm(A, n, low, mid);
	cout << "ls " << leftSum << endl;
	int rightSum = maximumSubArrayAlgorithm(A, n, mid+1, high);
	cout << "rs " << rightSum <<endl;
	int crossSum = maxCrossingAlgorithm(A, n, low, mid, high);
	cout << "cs " << crossSum << endl;
	if(leftSum >= rightSum && leftSum >= crossSum){
		return leftSum;
	} else if(rightSum >= leftSum && rightSum >= crossSum){
		return rightSum;
	}
	return crossSum;
	*/
	return max(maximumSubArrayAlgorithm(A, n, low, mid), 
              maximumSubArrayAlgorithm(A, n, mid+1, high), 
              maxCrossingAlgorithm(A,n, low, mid, high)); 

}

#endif

// A utility funtion to find maximum of two integers 
int max(int a, int b) { return (a > b)? a : b; } 
  
// A utility funtion to find maximum of three integers 
int max(int a, int b, int c) { return max(max(a, b), c); } 
  
// Find the maximum possible sum in arr[] auch that arr[m] is part of it 
int maxCrossingSum(int arr[], int l, int m, int h) 
{ 
    // Include elements on left of mid. 
    int sum = 0; 
    int left_sum = INT_MIN; 
    for (int i = m; i >= l; i--) 
    { 
        sum = sum + arr[i]; 
        if (sum > left_sum) 
          left_sum = sum; 
    } 
  
    // Include elements on right of mid 
    sum = 0; 
    int right_sum = INT_MIN; 
    for (int i = m+1; i <= h; i++) 
    { 
        sum = sum + arr[i]; 
        if (sum > right_sum) 
          right_sum = sum; 
    } 
  
    // Return sum of elements on left and right of mid 
    return left_sum + right_sum; 
} 
  
// Returns sum of maxium sum subarray in aa[l..h] 
int maxSubArraySum(int arr[], int l, int h) 
{ 
   // Base Case: Only one element 
   if (l == h) 
     return arr[l]; 
  
   // Find middle point 
   int m = (l + h)/2; 
  
   /* Return maximum of following three possible cases 
      a) Maximum subarray sum in left half 
      b) Maximum subarray sum in right half 
      c) Maximum subarray sum such that the subarray crosses the midpoint */
   return max(maxSubArraySum(arr, l, m), 
              maxSubArraySum(arr, m+1, h), 
              maxCrossingSum(arr, l, m, h)); 
} 
  
