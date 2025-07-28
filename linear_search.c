#include <stdio.h>

void main() {
	int n,i,key,pos, flag = 0;
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
	
	printf("\nEnter element to search: ");
	scanf("%d", &key);
	for ( i = 0; i < n; i++) {
		if ( A[i] == key ) {
			flag = 1;
			pos = i;
			break;
		}
	}
	
	if (flag)
		printf("Element was found at index %d", pos);
	else
		printf("Element was not found");
}
				
	
