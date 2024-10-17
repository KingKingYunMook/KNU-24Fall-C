#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void fillRandom(int array[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            array[i][j] = rand() % 20 + 1;
        }
    }
}

void printArray(int array[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%2d ", array[i][j]);
        }
        printf("\n");
    }
}

void movePointer(void* array) {
    int(*arr)[SIZE] = array;  
    int x = 0, y = 0;
    int steps = 0;

    while (1) {
        printf("���� ��ġ: (%d, %d), �迭�� ��: %2d\n", x, y, arr[x][y]);
        steps++;

        int move = arr[x][y];
        y += move;

        if (y >= SIZE) {
            x++;  // ���� ������ �̵�
            y %= SIZE;  // y ���� SIZE�� ���� �������� ����
        }

        if (x >= SIZE || (x == SIZE - 1 && y == SIZE - 1)) {
            printf("�� �̻� �̵��� �� �����ϴ�.\n");
            break;
        }
    }

    printf("�� �̵� Ƚ��: %d\n", steps);
}

int main() {
    srand(time(NULL)); // ���� �õ� �ʱ�ȭ
    int array[SIZE][SIZE];

    fillRandom(array);
    printArray(array); 
    movePointer(array); 

    return 0;
}