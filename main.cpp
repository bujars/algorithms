#include <cstdlib>
#include <cassert>
#include <iostream>
#include <stdio.h>
#include "linearSearchAlgorithm.cpp"
#include "binarySearchAlgorithm.cpp"
#include "insertionSortAlgorithm.cpp"
#include "mergeSortAlgorithm.cpp"
#include "heapSortAlgorithm.cpp"
#include "quickSortAlgorithm.cpp"
#include "countingSortAlgorithm.cpp"
#include "maximumSubArrayAlgorithm.cpp"
using namespace std;



void print(int A[], size_t n){
	for(size_t i = 0; i < n; i++){
		cout << A[i] << " ";
	}
	cout << "\n";
}



int main(){
	int A[3];
	A[0]=1;
	A[1]=2;
	A[2]=3;
	bool lSA = linearSearchAlgorithm(A, 3, 4);
	cout << lSA << "\n";
	lSA = linearSearchAlgorithm(A, 3, 2);
	cout << lSA << "\n";

	bool bSA = binarySearchAlgorithm(A, 3, 0, 2, 4);
	cout << bSA << "\n";
	bSA = binarySearchAlgorithm(A, 3, 0, 2, 1);
	cout << bSA << "\n";
	
	bool isASorted = isSorted(A, 3);
	cout << isASorted << "\n";
	A[2] = 0;
	cout << isSorted(A, 3) << "\n";
	A[2] = 3; 

	size_t size = 10;
	int Array [size] = { 1, 5, 3, 7, 2, 9, 8, 0, 6 , 4};
	int B [size];
	print(Array, size);
	
	cout << "B " << endl;
	print(B, size);
	//insertionSortAlgorithm(Array, size);
	/*cout << "here?" << endl;*/
    //mergeSortAlgorithm(Array, size, 0, 9);
	//heapSortAlgorithm(Array, size);
	//quickSortAlgorithm(Array, size, 0, 9);
	countingSortAlgorithm(Array, B, size);
	print(Array, size);
	print(B, size);
	cout << endl;
	/*int arr[] = {2, 3, 4, 5,7};
	int max_sum = maximumSubArrayAlgorithm(arr, 5, 0, 4);
	cout << "Maximum = " << max_sum << endl;*/
	
	int arr[] = {2, 3, 4, 5, 7}; 
   	int n = sizeof(arr)/sizeof(arr[0]); 
   	int max_sum = maxSubArraySum(arr, 0, n-1); 
   	printf("Maximum contiguous sum is %dn", max_sum); 
   	getchar(); 
	return 0;
}
