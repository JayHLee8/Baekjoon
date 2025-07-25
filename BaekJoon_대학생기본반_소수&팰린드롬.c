#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// 팰린드롬 판별 함수
bool is_palindrome(int n) {
    int original = n, reversed = 0;
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return original == reversed;
}

// 소수 판별 함수
bool is_prime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false; // 아래 반복문에 포함시켜 i=2부터 검사도 가능하지만, 짝수를 건너뛰어 효율을 높임
    int root = (int)sqrt(n); // sqrt(n)은 제곱근을 구하는 함수입니다.
    for (int i = 3; i <= root; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int N;
    printf("N을 입력하세요 (1 <= N <= 1000000): ");
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