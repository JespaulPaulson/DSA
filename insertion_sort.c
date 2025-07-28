#include <stdio.h>

void main() {
	int n,i,j;
	printf("Enter no: of elements: ");
	scanf("%d", &n);
	int A[n];
	
	for ( i = 0 ; i < n; i++) {
		printf("Enter element: ");
		scanf("%d", &A[i]);
	}
	
	printf("Array: ");
	for ( i = 0 ; i < n; i++) {
		printf("%d \t", A[i]);
	}
	
	for ( i = 1; i < n; i++) {
		int key = A[i];
		j = i - 1;
		while ( j >= 0 && A[j] > key) {
			A[j+1] = A[j];
			j--;
			A[j+1] = key;
		}
	}
	printf("Sorted Array: ");
	for (int k = 0 ; k < n; k++) {
		printf("%d \t", A[k]);
	}
}
