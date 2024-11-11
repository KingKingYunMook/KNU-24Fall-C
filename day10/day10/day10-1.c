#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[50];
    int score;
    struct Node* next;
} Node;

Node* head = NULL;

// 학생 삽입 (노드 생성)
void insertStudent(char* name, int score) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy_s(newNode->name, sizeof(newNode->name), name);
    newNode->score = score;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// 전체 학생 출력
void printAllStudents() {
    Node* current = head;
    while (current != NULL) {
        printf("%s : %d\n", current->name, current->score);
        current = current->next;
    }
}

// 학생 정보 삭제
void deleteStudent(char* name) {
    Node* current = head;
    Node* prev = NULL;

    while (current != NULL && strcmp(current->name, name) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) return;

    if (prev == NULL) {
        head = current->next;
    }
    else {
        prev->next = current->next;
    }
    free(current);
}

int main() {
    int choice;
    char name[50];
    int score;

    while (1) {
        printf("1. 학생의 성적을 입력\n");
        printf("2. 학생 정보 제거\n");
        printf("3. 프로그램 종료\n");
        printf("input : ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("학생 이름: ");
            scanf_s("%s", name, (unsigned)sizeof(name));
            printf("%s의 성적: ", name);
            scanf_s("%d", &score);
            insertStudent(name, score);
            printf("\n");
            printAllStudents();
            printf("\n");
            break;
        case 2:
            printf("삭제할 학생 이름: ");
            scanf_s("%s", name, (unsigned)sizeof(name));
            deleteStudent(name);
            printf("\n");
            printAllStudents();
            break;
        case 3:
            return 0;
        }
    }
}