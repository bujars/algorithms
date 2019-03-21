#include <cstdlib>
using namespace std;

/*NOTE this is the code for linear search. Just wrote it here to test out a file. Will be updating soon.*/
bool binarySearchAlgorithm(int A[], size_t n, int x){
	for(size_t i = 0; i < n; i++){
		if(A[i]==x){
			return true;	
		}
	}
	return false;
}



