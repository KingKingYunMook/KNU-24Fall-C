#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;  
    double discriminant, root1, root2;

    printf("a �� �Է�: ");
    scanf_s("%lf", &a);
    printf("b �� �Է�: ");
    scanf_s("%lf", &b);
    printf("c �� �Է�: ");
    scanf_s("%lf", &c);

    // �Ǻ�t��
    discriminant = pow(b, 2) - 4 * a * c;





    if (discriminant > 0) {
        // ���δݸ� �Ǳ�
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("�� ���� ���� �ٸ� �Ǳ�:\n");
        printf("x1 = %.2lf\n", root1);
        printf("x2 = %.2lf\n", root2);
    }
    else if (discriminant == 0) {
        ///�߱�
        root1 = -b / (2 * a);
        printf("�߱�:\n");
        printf("x = %.2lf\n", root1);
    }
    else {
        
        printf("����Դϴ�\n");
    }

    return 0;
}