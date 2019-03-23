#include <cstdlib>
#include <cassert>
#include <iostream>
#include "linearSearchAlgorithm.cpp"
#include "binarySearchAlgorithm.cpp"
#include "insertionSortAlgorithm.cpp"
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
	int Array [size] = { 1, 5, 3, 7, 2, 9, 8, 0, 6, 4 };
	print(Array, size);
	insertionSortAlgorithm(Array, size);
	print(Array, size);
	
	return 0;
}
