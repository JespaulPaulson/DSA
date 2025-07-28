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
	for (i = 0; i < n - 1; i++) {
		for ( j = 0; j < n - i - 1; j++) {
			if ( A[j] > A[j + 1] ) {
				int temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
		}
	}
	printf("\nSorted Array: ");
	for ( i = 0 ; i < n; i++) {
		printf("%d \t", A[i]);
	}
}
		
