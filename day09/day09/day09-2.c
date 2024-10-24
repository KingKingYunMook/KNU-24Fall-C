#include <stdio.h>

// 상품 정 구조체
typedef struct {
    int id;       
    char name[50]; 
    int price;    
}Product;

// 상품 정보를 출력하는 함수
void printProduct(Product p) {
    printf("상품 ID : %d\n", p.id);
    printf("상품명 : %s\n", p.name);
    printf("가격 : %d\n", p.price);
}

int main() {
    Product products[5];
    int count = 0;     
    int id;

    // 상품 정보 입력
    while (count < 5) {
        printf("상품 정보를 입력하세요 (입력 중단은 id에 0 입력)\n");
        printf("상품 ID : ");
        scanf_s("%d", &id);

        if (id == 0) {
            break;
        }

        products[count].id = id;

        printf("상품명 : ");
        scanf_s("%s", products[count].name,50);

        printf("가격 : ");
        scanf_s("%d", &products[count].price);

        count++;
    }

    // 입력된 상품 목록 출력
    printf("\n<<입력된 상품 목록>>\n");
    for (int i = 0; i < count; i++) {
        printProduct(products[i]);
        printf("\n");
    }

    return 0;
}
