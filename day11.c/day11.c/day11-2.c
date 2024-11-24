#include <stdio.h>
#include <math.h>

// 함수 f(x) = -log10(1/x) + sin(x)
double f(double x) {
    return -log10(1.0 / x) + sin(x);
}

// 수정된 구분구적법으로 적분 계산
double calculateIntegral(double a, double b, int n) {
    double dx = (b - a) / n;
    double sum = 0.0;

    // 각 구간의 중점에서 함수값을 계산하여 적분
    for (int i = 0; i < n; i++) {
        double x_mid = a + (i + 0.5) * dx;  // 각 구간의 중점
        sum += f(x_mid);
    }

    return sum * dx;  // 전체 면적 계산
}

int main() {
    double a, b;     // 적분 구간
    int max_power;   // 최대 2의 거듭제곱

    // 사용자 입력
    printf("적분할 시작 값을 입력하세요: ");
    scanf_s("%lf", &a);
    printf("적분할 끝 값을 입력하세요: ");
    scanf_s("%lf", &b);
    printf("시행할 최대 구간을 입력하세요 (2^n): ");
    scanf_s("%d", &max_power);

    printf("\n");
    // 첫 번째 부분: 1부터 32까지의 구간
    for (int i = 0; i <= 5; i++) {
        int n = (int)pow(2, i);
        double result = calculateIntegral(a, b, n);
        printf("구간\t%d 적분 결과: %.6f\n", n, result);
    }

    printf("\n");
    // 두 번째 부분: 큰 구간들
    for (int i = 21; i <= 26; i++) {  // 더 적은 수의 반복으로 수정
        int n = (int)pow(2, i);
        double result = calculateIntegral(a, b, n);
        printf("구간\t%d 적분 결과: %.6f\n", n, result);
    }

    return 0;
}