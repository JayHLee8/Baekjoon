#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_N 100

// �Է°� Ȯ�� �Լ�
int check_input(int* N, char map[MAX_N][MAX_N + 2]) {
    printf("���� N�� �Է��ϼ��� (1~100): ");
    if (scanf("%d", N) != 1 || *N < 1 || *N > 100) {
        printf("N���� �ùٸ��� �ʽ��ϴ�.\n");
        return 1;
    }
    getchar(); // ���ۿ� ���� ���๮�� ����

    printf("���簢���� �Է��ϼ��� ('.' �Ǵ� 'X'�� ���, �� �ٸ��� %d����):\n", *N);
    for (int i = 0; i < *N; i++) {
        if (fgets(map[i], sizeof(map[i]), stdin) == NULL) {
            printf("�Է� ����: ���� �����մϴ�.\n");
            return 1;
        }
        int len = strlen(map[i]);
        // ���๮�� ����
        if (map[i][len - 1] == '\n') {
            map[i][len - 1] = '\0';
            len--;
        }
        if (len != *N) {
            printf("�Է� ����: %d��° ���� ���̰� %d�� �ƴմϴ�.\n", i + 1, *N);
            return 1;
        }
        for (int j = 0; j < *N; j++) {
            if (map[i][j] != '.' && map[i][j] != 'X') {
                printf("�Է� ����: %d��° �ٿ� ������ ���� ���ڰ� �ֽ��ϴ�.\n", i + 1);
                return 1;
            }
        }
    }
    return 0;
}

// ���� ���� ���� ���� ����
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

// ���� ���� ���� ���� ����
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
    char map[MAX_N][MAX_N + 2]; // +2�� ���๮�ڿ� �ι��� ���

    if (check_input(&N, map) != 0) {
        return 1;
    }
    printf("�Է��� �ùٸ��ϴ�.\n");

    int horizontal = count_horizontal(N, map);
    int vertical = count_vertical(N, map);
    printf("����: %d\n����: %d\n", horizontal, vertical);

    return 0;
}