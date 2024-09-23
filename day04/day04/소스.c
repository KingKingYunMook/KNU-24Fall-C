#include <stdio.h>

int main(void) {
	int a = 15;
	int pa = &a;

	printf("%d\n", &a);
	printf("%d", pa);

	return 0;

}