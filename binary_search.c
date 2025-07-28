#include <stdio.h>

void main() {
	int n,i,j,key,pos, flag = 0;
	printf("Enter no: of elements: ");
	scanf("%d", &n);
	int A[n];
	
	for ( i = 0 ; i < n; i++) {
		printf("Enter element: ");
		scanf("%d", &A[i]);
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
	
	printf("Sorted Array: ");
	for ( i = 0 ; i < n; i++) {
		printf("%d \t", A[i]);
	}
	
	printf("\nEnter element to search: ");
	scanf("%d", &key);
	
	int low = 0, high = n - 1;
	while ( low <= high ) {
		int mid = ( low + high ) / 2;
		if ( A[mid] == key ) {
			flag = 1;
			pos = mid;
			break;
		}
		else if ( A[mid] > key ) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	
	if (flag)
		printf("Element was found at index %d", pos);
	else
		printf("Element was not found");
}
			
			
			
			
			
			
			
			
			
			
			
			
	
