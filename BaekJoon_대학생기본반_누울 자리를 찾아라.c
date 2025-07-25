#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_N 100

// 입력값 확인 함수
int check_input(int* N, char map[MAX_N][MAX_N + 2]) {
    printf("정수 N을 입력하세요 (1~100): ");
    if (scanf("%d", N) != 1 || *N < 1 || *N > 100) {
        printf("N값이 올바르지 않습니다.\n");
        return 1;
    }
    getchar(); // 버퍼에 남은 개행문자 제거

    printf("정사각형을 입력하세요 ('.' 또는 'X'만 사용, 각 줄마다 %d글자):\n", *N);
    for (int i = 0; i < *N; i++) {
        if (fgets(map[i], sizeof(map[i]), stdin) == NULL) {
            printf("입력 오류: 줄이 부족합니다.\n");
            return 1;
        }
        int len = strlen(map[i]);
        // 개행문자 제거
        if (map[i][len - 1] == '\n') {
            map[i][len - 1] = '\0';
            len--;
        }
        if (len != *N) {
            printf("입력 오류: %d번째 줄의 길이가 %d가 아닙니다.\n", i + 1, *N);
            return 1;
        }
        for (int j = 0; j < *N; j++) {
            if (map[i][j] != '.' && map[i][j] != 'X') {
                printf("입력 오류: %d번째 줄에 허용되지 않은 문자가 있습니다.\n", i + 1);
                return 1;
            }
        }
    }
    return 0;
}

// 가로 연속 공간 개수 세기
int count_horizontal(int N, char map[MAX_N][MAX_N + 2]) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        int len = 0;
        for (int j = 0; j < N; j++) {
            if (map[i][j] == '.') {
                len++;
            }
            else {
                if (len >= 2) count++;
                len = 0;
            }
        }
        if (len >= 2) count++;
    }
    return count;
}

// 세로 연속 공간 개수 세기
int count_vertical(int N, char map[MAX_N][MAX_N + 2]) {
    int count = 0;
    for (int j = 0; j < N; j++) {
        int len = 0;
        for (int i = 0; i < N; i++) {
            if (map[i][j] == '.') {
                len++;
            }
            else {
                if (len >= 2) count++;
                len = 0;
            }
        }
        if (len >= 2) count++;
    }
    return count;
}

int main() {
    int N;
    char map[MAX_N][MAX_N + 2]; // +2는 개행문자와 널문자 고려

    if (check_input(&N, map) != 0) {
        return 1;
    }
    printf("입력이 올바릅니다.\n");

    int horizontal = count_horizontal(N, map);
    int vertical = count_vertical(N, map);
    printf("가로: %d\n세로: %d\n", horizontal, vertical);

    return 0;
}