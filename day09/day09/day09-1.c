#include <stdio.h>


typedef struct {
    float x;
    float y;
    float z;

} Vector3D;

Vector3D add_vectors(Vector3D v1, Vector3D v2) {
    Vector3D result;
    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;
    result.z = v1.z + v2.z;
    return result;
}

Vector3D subtract_vectors(Vector3D v1, Vector3D v2) {
    Vector3D result;
    result.x = v1.x - v2.x;
   
    result.y = v1.y - v2.y;
    result.z = v1.z - v2.z;
    return result;
}

float dot_product(Vector3D v1, Vector3D v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

Vector3D cross_product(Vector3D v1, Vector3D v2) {
    Vector3D result;
    result.x = v1.y * v2.z - v1.z * v2.y;
    result.y = v1.z * v2.x - v1.x * v2.z;
    result.z = v1.x * v2.y - v1.y * v2.x;
    return result;
}

int main() {
    Vector3D vec1 = { 1, 3, 4 };   
    Vector3D vec2 = { 2, 4, 1 };   
    int choice;

    printf("ù��° ����(x,y,z): %.0f, %.0f, %.0f\n", vec1.x, vec1.y, vec1.z);
    printf("�ι�° ����(x,y,z): %.0f, %.0f, %.0f\n", vec2.x, vec2.y, vec2.z);
    
    
    printf("�Էµ� ù��° ����\t%.0f,\t%.0f,\t%.0f\n", vec1.x, vec1.y, vec1.z);
    
    printf("�Էµ� �ι�° ����\t%.0f,\t%.0f,\t%.0f\n", vec2.x, vec2.y, vec2.z);
    printf("\n1. ������ ��\n");
    printf("2. ������ ��\n");

    printf("3. ������ ����\n");



    printf("4. ������ ����\n");
    printf("5. ����\n");
    printf("�޴� �Է� : ");
    scanf_s("%d", &choice);

    switch (choice) {
    case 1: {
        Vector3D sum = add_vectors(vec1, vec2);
        printf("\n������ ���� x:%.0f y:%.0f z:%.0f\n", sum.x, sum.y, sum.z);
        break;
    }


    case 2: {
        Vector3D diff = subtract_vectors(vec1, vec2);
        printf("\n������ ���� x:%.0f y:%.0f z:%.0f\n", diff.x, diff.y, diff.z);
        break;
    }
    case 3: {
        Vector3D cross = cross_product(vec1, vec2);
        printf("\n������ ������ x:%.0f y:%.0f z:%.0f\n", cross.x, cross.y, cross.z);
        break;
    }
    case 4: {
        float dot = dot_product(vec1, vec2);


        printf("\n������ ������ vec1 �� vec2=%.0f\n", dot);
        break;
    }
    case 5:
        printf("���α׷��� �����մϴ�.\n");
        break;
    default:
        printf("�߸��� �����Դϴ�.\n");
    }

    return 0;
}