#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// �Ӹ���� �Ǻ� �Լ�
bool is_palindrome(int n) {
    int original = n, reversed = 0;
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return original == reversed;
}

// �Ҽ� �Ǻ� �Լ�
bool is_prime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false; // �Ʒ� �ݺ����� ���Խ��� i=2���� �˻絵 ����������, ¦���� �ǳʶپ� ȿ���� ����
    int root = (int)sqrt(n); // sqrt(n)�� �������� ���ϴ� �Լ��Դϴ�.
    for (int i = 3; i <= root; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int N;
    printf("N�� �Է��ϼ��� (1 <= N <= 1000000): ");
    scanf("%d", &N);

    int num = N;
    while (1) {
        if (is_palindrome(num)) {
            if (is_prime(num)) {
                printf("%d\n", num);
                break;
            }
        }
        num++;
    }
    return 0;
}