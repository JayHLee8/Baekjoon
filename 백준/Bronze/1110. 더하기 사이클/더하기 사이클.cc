#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int cycleCount(int N) {
    int sum, newN;
    int cycle = 0;

	int original = N; // 원래 입력값 저장

    while (1) {
        int tempN = N;

        // 십의 자리와 일의 자리 더하기
        int tens = tempN / 10;
        int ones = tempN % 10;
        sum = tens + ones;

        // N의 일의 자리와 firstAdd의 일의 자리를 붙여 새로운 N 만들기
        int sumOnes = sum % 10;
        newN = ones * 10 + sumOnes;

        N = newN; // 새로운 N으로 업데이트
        cycle++; // 사이클 수 증가
        if (N == original)
            break;// 원래 입력값과 같아지면 반복 종료
    }
	return cycle;
}

int main() {
    int N;

    // 사용자로부터 0<=N<=99인 정수 입력받기
    scanf("%d", &N);

    // 입력값 검증
    if (N < 0 || N > 99) {
        printf("0부터 99 사이의 정수를 입력해주세요.\n");
        return 1;
    }

    // 결과 출력
    printf("%d\n", cycleCount(N));

    return 0;
}