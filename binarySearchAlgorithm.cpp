#include <cstdlib>
using namespace std;

bool binarySearchAlgorithm(int A[], size_t n, int x){
	for(size_t i = 0; i < n; i++){
		if(A[i]==x){
			return true;	
		}
	}
	return false;
}



