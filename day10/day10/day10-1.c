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

// 정렬된 위치에 노드 삽입
void insert_node_sorted(char* name, int score) {
    struct NODE* new_node = create_node(name, score);

    // 리스트가 비어있거나 첫 노드보다 점수가 높은 경우를ㄹ판별하는 거이
    if (head == NULL || head->score < score) {
        new_node->link = head;
        head = new_node;
        return;
    }
    //위치 찾기
    struct NODE* cur = head;
    while (cur->link != NULL && cur->link->score >= score) {
        cur = cur->link;
    }

    new_node->link = cur->link;
    cur->link = new_node;
}

// 모든 노드 출력
void print_nodes() {
    printf("\n----------------------------------------\n");
    struct NODE* cur = head;
    while (cur != NULL) {
        printf("%s : %d\n", cur->name, cur->score);
        cur = cur->link;
    }
    printf("----------------------------------------\n");
}

// 학생 찾기
struct NODE* find_node(char* name) {
    struct NODE* cur = head;
    while (cur != NULL) {
        if (strcmp(cur->name, name) == 0) return cur;
        cur = cur->link;
    }
    return NULL;
}

// 학생 삭제
int delete_node(char* name) {
    if (head == NULL) return 0;

    struct NODE* prev = head;
    struct NODE* cur;

    // 첫 노드인 경우
    if (strcmp(head->name, name) == 0) {
        cur = head;
        head = head->link;
        free(cur);
        return 1;
    }

    // 그 외의 경우
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
        printf("\n1. 학생의 성적을 입력\n");
        printf("2. 학생 정보 제거\n");
        printf("3. 프로그램 종료\n");
        printf("input : ");
        scanf_s("%d", &choice);
        getchar();

        switch (choice) {
        case 1:
            printf("학생 이름: ");
            scanf_s("%s", name, (unsigned)sizeof(name));
            printf("%s의 성적: ", name);
            scanf_s("%d", &score);
            insert_node_sorted(name, score);  // 정렬된 위치에 삽입
            print_nodes();
            break;

        case 2:
            printf("삭제할 학생 이름: ");
            scanf_s("%s", name, (unsigned)sizeof(name));
            if (delete_node(name)) {
                printf("삭제 완료\n");
                print_nodes();
            }
            else {
                printf("학생을 찾을 수 없습니다.\n");
            }
            break;

        case 3:
            printf("프로그램을 종료합니다.\n");
            // 메모리 해제
            while (head != NULL) {
                struct NODE* temp = head;
                head = head->link;
                free(temp);
            }
            return 0;

        default:
            printf("잘못된 선택입니다.\n");
        }
    }

    return 0;
}