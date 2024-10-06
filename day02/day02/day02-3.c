#include<stdio.h>

int main(void) {

	for (int k = 0; k <= 99; k++) {
		if ((k % 3 == 0 && k % 4 == 0) || k % 7 == 0) {
			printf("%2d ", k);
		}
	}
	return 0;
}