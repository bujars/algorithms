#include <cstdlib>
#include <cassert>
#include <iostream>
#include "linearSearchAlgorithm.cpp"
#include "binarySearchAlgorithm.cpp"
using namespace std;



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
	
	
	return 0;
}
