#include <cstdlib>
using namespace std;


/* Note this is a brute force algorithm, meaning its the 'easiest' way to think about and the first answer one would often come to.
 * It goes through each element in the array and makes a comparsion.
 * The Time Complexity is Big-O(n). This is becasue we can potentially find out element in the first position, the second, the last, or not at all! Hence its the worst case scenario. */
bool linearSearchAlgorithm(int A[], size_t n, int x){
	for(size_t i = 0; i < n; i++){
		if(A[i]==x){
			return true;	
		}
	}
	return false;
}
