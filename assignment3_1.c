#include <stdio.h>

float test[] = {10, 0.25, -2342, 12123, 3.145435, 6, 6, 5.999, -2, -5, -109.56};
int n = 11; //length of array
	    //
void swap(float* xp, float* yp)
{
    float temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort_numeric() {
	printf("Please input A to sort the array in ascending order or D to sort in descending order: ");
	char input;
	scanf("%c", &input);
	if (input == 'A' || input == 'a' ) {
		printf("Ascending\n");
 		int i, j, min_idx;
 
    		for (i = 0; i < n - 1; i++) {
 
      		// Find the minimum element in unsorted array
       		min_idx = i;
	        for (j = i + 1; j < n; j++)
        	    if (test[j] < test[min_idx])
	               	 min_idx = j;
 
        	// Swap the found minimum element
      		  // with the first element
        	swap(&test[min_idx], &test[i]);
		}
	}

	else if (input == 'D' || input == 'd') {
		printf("Descending\n");
		 int i, j, max_idx;
 
    		// One by one move boundary of unsorted subarray
	   	 for (i = 0; i < n - 1; i++) {
 
        	// Find the minimum element in unsorted array
	        max_idx = i;
        	for (j = i + 1; j < n; j++)
            	if (test[j] > test[max_idx])
                	max_idx = j;
 
       		 // Swap the found maximum element
        	// with the first element
       		 swap(&test[max_idx], &test[i]);
		}
	}
}

int main() {
	sort_numeric();
	for (int i = 0; i < n - 1; i++) {
		printf("%f, ", test[i]);
	}
	printf("%f\n", test[n-1]);
	return 0;
}
	

