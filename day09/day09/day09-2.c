#include <stdio.h>

// ��ǰ �� ����ü
typedef struct {
    int id;       
    char name[50]; 
    int price;    
}Product;

// ��ǰ ������ ����ϴ� �Լ�
void printProduct(Product p) {
    printf("��ǰ ID : %d\n", p.id);
    printf("��ǰ�� : %s\n", p.name);
    printf("���� : %d\n", p.price);
}

int main() {
    Product products[5];
    int count = 0;     
    int id;

    // ��ǰ ���� �Է�
    while (count < 5) {
        printf("��ǰ ������ �Է��ϼ��� (�Է� �ߴ��� id�� 0 �Է�)\n");
        printf("��ǰ ID : ");
        scanf_s("%d", &id);

        if (id == 0) {
            break;
        }

        products[count].id = id;

        printf("��ǰ�� : ");
        scanf_s("%s", products[count].name,50);

        printf("���� : ");
        scanf_s("%d", &products[count].price);

        count++;
    }

    // �Էµ� ��ǰ ��� ���
    printf("\n<<�Էµ� ��ǰ ���>>\n");
    for (int i = 0; i < count; i++) {
        printProduct(products[i]);
        printf("\n");
    }

    return 0;
}
