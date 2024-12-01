#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int topping[], size_t topping_len) {
    int answer = 0;

    int left_count[10001] = { 0 };
    int right_count[10001] = { 0 };
    int left_types = 0;
    int right_types = 0;

    for (size_t i = 0; i < topping_len; i++) {
        if (right_count[topping[i]] == 0) {
            right_types++;
        }
        right_count[topping[i]]++;
    }

    for (size_t i = 0; i < topping_len; i++) {
        right_count[topping[i]]--;
        if (right_count[topping[i]] == 0) {
            right_types--;
        }

        if (left_count[topping[i]] == 0) {
            left_types++;
        }
        left_count[topping[i]]++;

        if (left_types == right_types) {
            answer++;
        }
    }

    return answer;
}

int main() {
    // 테스트 케이스 1
    int topping1[] = { 1, 2, 1, 3, 1, 4, 1, 2 };
    size_t len1 = sizeof(topping1) / sizeof(topping1[0]);
    printf("\n테스트 케이스 1 입력값: ");
    for (size_t i = 0; i < len1; i++) {
        printf("%d ", topping1[i]);
    }
    printf("\n결과: %d\n", solution(topping1, len1));  // 예상 결과: 2

    // 테스트 케이스 2
    int topping2[] = { 1, 2, 3, 1, 4 };
    size_t len2 = sizeof(topping2) / sizeof(topping2[0]);
    printf("\n테스트 케이스 2 입력값: ");
    for (size_t i = 0; i < len2; i++) {
        printf("%d ", topping2[i]);
    }
    printf("\n결과: %d\n", solution(topping2, len2));  // 예상 결과: 0

    // 테스트 케이스 3
    int topping3[] = { 1, 1, 1, 1, 1, 1 };
    size_t len3 = sizeof(topping3) / sizeof(topping3[0]);
    printf("\n테스트 케이스 3 입력값: ");
    for (size_t i = 0; i < len3; i++) {
        printf("%d ", topping3[i]);
    }
    printf("\n결과: %d\n", solution(topping3, len3));  // 예상 결과: 5

    // 테스트 케이스 4
    int topping4[] = { 1, 2, 3, 4, 5 };
    size_t len4 = sizeof(topping4) / sizeof(topping4[0]);
    printf("\n테스트 케이스 4 입력값: ");
    for (size_t i = 0; i < len4; i++) {
        printf("%d ", topping4[i]);
    }
    printf("\n결과: %d\n", solution(topping4, len4));  // 예상 결과: 0

    // 테스트 케이스 5
    int topping5[] = { 1, 2, 2, 1 };
    size_t len5 = sizeof(topping5) / sizeof(topping5[0]);
    printf("\n테스트 케이스 5 입력값: ");
    for (size_t i = 0; i < len5; i++) {
        printf("%d ", topping5[i]);
    }
    printf("\n결과: %d\n", solution(topping5, len5));  // 예상 결과: 2

    return 0;
}