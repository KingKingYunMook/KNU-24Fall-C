#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NODE {
    char name[50];
    int score;
    struct NODE* link;
};

struct NODE* head = NULL;

struct NODE* create_node(char* name, int score) {
    struct NODE* new_node = (struct NODE*)malloc(sizeof(struct NODE));
    strcpy_s(new_node->name, sizeof(new_node->name), name);
    new_node->score = score;
    new_node->link = NULL;
    return new_node;
}

// ���ĵ� ��ġ�� ��� ����
void insert_node_sorted(char* name, int score) {
    struct NODE* new_node = create_node(name, score);

    // ����Ʈ�� ����ְų� ù ��庸�� ������ ���� ��츦���Ǻ��ϴ� ����
    if (head == NULL || head->score < score) {
        new_node->link = head;
        head = new_node;
        return;
    }
    //��ġ ã��
    struct NODE* cur = head;
    while (cur->link != NULL && cur->link->score >= score) {
        cur = cur->link;
    }

    new_node->link = cur->link;
    cur->link = new_node;
}

// ��� ��� ���
void print_nodes() {
    printf("\n----------------------------------------\n");
    struct NODE* cur = head;
    while (cur != NULL) {
        printf("%s : %d\n", cur->name, cur->score);
        cur = cur->link;
    }
    printf("----------------------------------------\n");
}

// �л� ã��
struct NODE* find_node(char* name) {
    struct NODE* cur = head;
    while (cur != NULL) {
        if (strcmp(cur->name, name) == 0) return cur;
        cur = cur->link;
    }
    return NULL;
}

// �л� ����
int delete_node(char* name) {
    if (head == NULL) return 0;

    struct NODE* prev = head;
    struct NODE* cur;

    // ù ����� ���
    if (strcmp(head->name, name) == 0) {
        cur = head;
        head = head->link;
        free(cur);
        return 1;
    }

    // �� ���� ���
    cur = head->link;
    while (cur != NULL) {
        if (strcmp(cur->name, name) == 0) {
            prev->link = cur->link;
            free(cur);
            return 1;
        }
        prev = cur;
        cur = cur->link;
    }
    return 0;
}

int main() {
    int choice;
    char name[50];
    int score;

    while (1) {
        printf("\n1. �л��� ������ �Է�\n");
        printf("2. �л� ���� ����\n");
        printf("3. ���α׷� ����\n");
        printf("input : ");
        scanf_s("%d", &choice);
        getchar();

        switch (choice) {
        case 1:
            printf("�л� �̸�: ");
            scanf_s("%s", name, (unsigned)sizeof(name));
            printf("%s�� ����: ", name);
            scanf_s("%d", &score);
            insert_node_sorted(name, score);  // ���ĵ� ��ġ�� ����
            print_nodes();
            break;

        case 2:
            printf("������ �л� �̸�: ");
            scanf_s("%s", name, (unsigned)sizeof(name));
            if (delete_node(name)) {
                printf("���� �Ϸ�\n");
                print_nodes();
            }
            else {
                printf("�л��� ã�� �� �����ϴ�.\n");
            }
            break;

        case 3:
            printf("���α׷��� �����մϴ�.\n");
            // �޸� ����
            while (head != NULL) {
                struct NODE* temp = head;
                head = head->link;
                free(temp);
            }
            return 0;

        default:
            printf("�߸��� �����Դϴ�.\n");
        }
    }

    return 0;
}