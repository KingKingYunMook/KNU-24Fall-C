#include <stdio.h>
#include <math.h>

// �Լ� f(x) = -log10(1/x) + sin(x)
double f(double x) {
    return -log10(1.0 / x) + sin(x);
}

// ������ ���б��������� ���� ���
double calculateIntegral(double a, double b, int n) {
    double dx = (b - a) / n;
    double sum = 0.0;

    // �� ������ �������� �Լ����� ����Ͽ� ����
    for (int i = 0; i < n; i++) {
        double x_mid = a + (i + 0.5) * dx;  // �� ������ ����
        sum += f(x_mid);
    }

    return sum * dx;  // ��ü ���� ���
}

int main() {
    double a, b;     // ���� ����
    int max_power;   // �ִ� 2�� �ŵ�����

    // ����� �Է�
    printf("������ ���� ���� �Է��ϼ���: ");
    scanf_s("%lf", &a);
    printf("������ �� ���� �Է��ϼ���: ");
    scanf_s("%lf", &b);
    printf("������ �ִ� ������ �Է��ϼ��� (2^n): ");
    scanf_s("%d", &max_power);

    printf("\n");
    // ù ��° �κ�: 1���� 32������ ����
    for (int i = 0; i <= 5; i++) {
        int n = (int)pow(2, i);
        double result = calculateIntegral(a, b, n);
        printf("����\t%d ���� ���: %.6f\n", n, result);
    }

    printf("\n");
    // �� ��° �κ�: ū ������
    for (int i = 21; i <= 26; i++) {  // �� ���� ���� �ݺ����� ����
        int n = (int)pow(2, i);
        double result = calculateIntegral(a, b, n);
        printf("����\t%d ���� ���: %.6f\n", n, result);
    }

    return 0;
}