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
	printf("�Ҽ����� Ȯ���� ���� �Է��ϼſ� : %");
	scanf_s("%d", &input);

	int result = isPrime(input);
	printf("%d", result);

	return 0;

}