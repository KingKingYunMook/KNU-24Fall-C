#include <stdio.h>

int pac(int num) {
	
	int pac_result;

	if (num == 1) {
		return 1;
	}
	pac_result = num * pac(num - 1);

}

int main(void) {


	int input;
	printf("����� ���丮�� �� �Է� : ");
	scanf_s("%d", &input);
	int result = pac(input);
	printf("%d! = %d", input, result);
	return 0;

}