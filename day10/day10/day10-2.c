#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Customer {
    char* customerName;
    int rank;           // 1: 최상위, 2: 중간, 3: 최하위
    int order_amount;
    int point;
    struct Customer* prev;
    struct Customer* next;
};

struct Customer* head = NULL;

struct Customer* create_customer(char* name, int rank, int amount, int point) {
    struct Customer* new_customer = (struct Customer*)malloc(sizeof(struct Customer));
    new_customer->customerName = (char*)malloc(strlen(name) + 1);
    strcpy(new_customer->customerName, name);
    new_customer->rank = rank;
    new_customer->order_amount = amount;
    new_customer->point = point;
    new_customer->prev = NULL;
    new_customer->next = NULL;
    return new_customer;
}

void insert_customer(char* name, int rank, int amount, int point) {
    struct Customer* new_customer = create_customer(name, rank, amount, point);

    if (head == NULL) {
        head = new_customer;
        return;
    }

    struct Customer* cur = head;
    while (cur != NULL) {
        if (new_customer->rank < cur->rank ||
            (new_customer->rank == cur->rank && new_customer->order_amount >= cur->order_amount)) {
            if (cur == head) {
                new_customer->next = head;
                head->prev = new_customer;
                head = new_customer;
            }
            else {
                new_customer->prev = cur->prev;
                new_customer->next = cur;
                cur->prev->next = new_customer;
                cur->prev = new_customer;
            }
            return;
        }
        if (cur->next == NULL) {
            cur->next = new_customer;
            new_customer->prev = cur;
            return;
        }
        cur = cur->next;
    }
}

void update_customer(char* name, int new_amount, int new_point) {
    struct Customer* cur = head;
    while (cur != NULL) {
        if (strcmp(cur->customerName, name) == 0) {
            cur->order_amount = new_amount;
            cur->point = new_point;
            return;
        }
        cur = cur->next;
    }
}

void delete_customer(char* name) {
    struct Customer* cur = head;
    while (cur != NULL) {
        if (strcmp(cur->customerName, name) == 0) {
            if (cur == head) {
                head = cur->next;
                if (head != NULL) head->prev = NULL;
            }
            else {
                cur->prev->next = cur->next;
                if (cur->next != NULL) cur->next->prev = cur->prev;
            }
            free(cur->customerName);
            free(cur);
            return;
        }
        cur = cur->next;
    }
}

void print_customers() {
    printf("\n===== 고객 리스트 =====\n");
    struct Customer* cur = head;
    while (cur != NULL) {
        printf("이름: %s, 등급: %d, 주문금액: %d, 포인트: %d\n",
            cur->customerName, cur->rank, cur->order_amount, cur->point);
        cur = cur->next;
    }
    printf("=====================\n");
}

int main() {
    int choice;
    char name[50];
    int rank, amount, point;

    while (1) {
        printf("\n1. 고객 추가\n");
        printf("2. 고객 정보 수정\n");
        printf("3. 고객 삭제\n");
        printf("4. 고객 리스트 출력\n");
        printf("5. 프로그램 종료\n");
        printf("선택: ");
        scanf_s("%d", &choice);
        getchar();

        switch (choice) {
        case 1:
            printf("고객 이름: ");
            scanf_s("%s", name, sizeof(name));
            printf("고객 등급 (1:최상위, 2:중간, 3:최하위): ");
            scanf_s("%d", &rank);
            printf("주문 금액: ");
            scanf_s("%d", &amount);
            printf("포인트: ");
            scanf_s("%d", &point);
            insert_customer(name, rank, amount, point);
            print_customers();
            break;

        case 2:
            printf("수정할 고객 이름: ");
            scanf_s("%s", name, sizeof(name));
            printf("새 주문 금액: ");
            scanf_s("%d", &amount);
            printf("새 포인트: ");
            scanf_s("%d", &point);
            update_customer(name, amount, point);
            print_customers();
            break;

        case 3:
            printf("삭제할 고객 이름: ");
            scanf_s("%s", name, sizeof(name));
            delete_customer(name);
            print_customers();
            break;

        case 4:
            print_customers();
            break;

        case 5:
            while (head != NULL) {
                struct Customer* temp = head;
                head = head->next;
                free(temp->customerName);
                free(temp);
            }
            return 0;

        default:
            printf("잘못된 선택입니다.\n");
        }
    }
    return 0;
}