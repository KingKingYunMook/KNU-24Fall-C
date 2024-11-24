#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;  
    double discriminant, root1, root2;

    printf("a 값 입력: ");
    scanf_s("%lf", &a);
    printf("b 값 입력: ");
    scanf_s("%lf", &b);
    printf("c 값 입력: ");
    scanf_s("%lf", &c);

    // 판별t식
    discriminant = pow(b, 2) - 4 * a * c;





    if (discriminant > 0) {
        // 서로닫른 실근
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("두 개의 서로 다른 실근:\n");
        printf("x1 = %.2lf\n", root1);
        printf("x2 = %.2lf\n", root2);
    }
    else if (discriminant == 0) {
        ///중근
        root1 = -b / (2 * a);
        printf("중근:\n");
        printf("x = %.2lf\n", root1);
    }
    else {
        
        printf("허근입니다\n");
    }

    return 0;
}