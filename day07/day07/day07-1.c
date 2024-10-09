#include <stdio.h>

void main() {
	int n;
	scanf_s("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = n; j > i; j--) {
			printf(" ");
		}

		for (int k = 1; k <= i*2 -1 ; k++) {
			printf("*");
		}
		printf("\n");
	}  

	
}