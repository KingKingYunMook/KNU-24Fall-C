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

    printf("첫번째 벡터(x,y,z): %.0f, %.0f, %.0f\n", vec1.x, vec1.y, vec1.z);
    printf("두번째 벡터(x,y,z): %.0f, %.0f, %.0f\n", vec2.x, vec2.y, vec2.z);
    
    
    printf("입력된 첫번째 벡터\t%.0f,\t%.0f,\t%.0f\n", vec1.x, vec1.y, vec1.z);
    
    printf("입력된 두번째 벡터\t%.0f,\t%.0f,\t%.0f\n", vec2.x, vec2.y, vec2.z);
    printf("\n1. 벡터의 합\n");
    printf("2. 벡터의 차\n");

    printf("3. 벡터의 외적\n");



    printf("4. 벡터의 내적\n");
    printf("5. 종료\n");
    printf("메뉴 입력 : ");
    scanf_s("%d", &choice);

    switch (choice) {
    case 1: {
        Vector3D sum = add_vectors(vec1, vec2);
        printf("\n벡터의 합은 x:%.0f y:%.0f z:%.0f\n", sum.x, sum.y, sum.z);
        break;
    }


    case 2: {
        Vector3D diff = subtract_vectors(vec1, vec2);
        printf("\n벡터의 차는 x:%.0f y:%.0f z:%.0f\n", diff.x, diff.y, diff.z);
        break;
    }
    case 3: {
        Vector3D cross = cross_product(vec1, vec2);
        printf("\n벡터의 외적은 x:%.0f y:%.0f z:%.0f\n", cross.x, cross.y, cross.z);
        break;
    }
    case 4: {
        float dot = dot_product(vec1, vec2);


        printf("\n벡터의 내적은 vec1 · vec2=%.0f\n", dot);
        break;
    }
    case 5:
        printf("프로그램을 종료합니다.\n");
        break;
    default:
        printf("잘못된 선택입니다.\n");
    }

    return 0;
}