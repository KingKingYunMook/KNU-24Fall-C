#include <stdio.h>

int isPrime(int n) {
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			return 0;
		}
		
	}
	return 1;
}

int main(void) {

	int input;
	printf("소수인지 확인할 수를 입력하셔요 : %");
	scanf_s("%d", &input);

	int result = isPrime(input);
	printf("%d", result);

	return 0;

}