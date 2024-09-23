#include <stdio.h>

void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

int main(void) {
	int a = 1, b = 2;
	printf("%d, %d", a, b);
	swap(&a, &b);
	printf("\n%d, %d", a, b);

	return 0;

}
