#include <cstdlib>
#include <cassert>
#include <iostream>
#include "binarySearchAlgorithm.cpp"
using namespace std;



int main(){
	int A[3];
	A[0]=1;
	A[1]=2;
	A[2]=3;
	bool bSA = binarySearchAlgorithm(A, 3, 4);
	cout << bSA << "\n";
	bSA = binarySearchAlgorithm(A, 3, 2);
	cout << bSA << "\n";
	return 0;
}
