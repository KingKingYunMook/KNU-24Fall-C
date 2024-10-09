#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {

	double x = 0;
	double y = 0;

	int count = 0, circle = 0;
	double fi;
	double is_in_circle;

	srand(time(NULL));

	while (count < 1000000000) {
		x = (double)rand() / (double)RAND_MAX;
		y = (double)rand() / (double)RAND_MAX; 
	
		is_in_circle = x*x + y*y; // ���������� sqrt�� ���ֵ� ��.
		int persent; 

		if (is_in_circle <= 1) {
			circle++;
		}
		count++;
		
		 
		if (count % 10000000 == 0) {  // �� õ�� ��° �ݺ����� ���

			fi = 4.0 * ((double)circle / count);

			persent = (int)((double)count / 1000000000 * 100);
			printf("%d%%���� | ������ : %f | ", persent, fi);
			for (int i = 5; i <= persent; i = i + 5)printf("��");
			for (int j = 5; j <= 100 - persent; j = j + 5)printf("��");
			printf("\n");
		}
		
		
	}
	fi = 4.0 * ((double)circle / count);
	printf("\n���� ������ : %f\n", fi); // 
} 