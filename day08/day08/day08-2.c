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
        printf("현재 위치: (%d, %d), 배열의 값: %2d\n", x, y, arr[x][y]);
        steps++;

        int move = arr[x][y];
        y += move;

        if (y >= SIZE) {
            x++;  // 다음 행으로 이동
            y %= SIZE;  // y 값을 SIZE로 나눈 나머지로 조정
        }

        if (x >= SIZE || (x == SIZE - 1 && y == SIZE - 1)) {
            printf("더 이상 이동할 수 없습니다.\n");
            break;
        }
    }

    printf("총 이동 횟수: %d\n", steps);
}

int main() {
    srand(time(NULL)); // 랜덤 시드 초기화
    int array[SIZE][SIZE];

    fillRandom(array);
    printArray(array); 
    movePointer(array); 

    return 0;
}