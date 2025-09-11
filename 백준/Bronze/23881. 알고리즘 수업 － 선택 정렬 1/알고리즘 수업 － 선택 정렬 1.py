def solve():
    N, K = map(int, input().split()) 
    A = list(map(int, input().split()))
    # split은 공백을 기본으로 함
    count = 0

    # 선택 정렬: 뒤에서부터 현재 구간의 최댓값을 제자리로
    for last in range(N - 1, 0, -1):
        # A[] 중 최댓값 위치 찾기 (앞에서부터 탐색)
        max_idx = 0
        for i in range(1, last + 1):
            if A[i] > A[max_idx]:
                max_idx = i

        # 필요할 때만 교환
        if max_idx != last:
            x = A[last]
            y = A[max_idx]
            A[last], A[max_idx] = A[max_idx], A[last]
            count += 1

            if count == K:
                if x < y:
                    print(x, y)
                else:
                    print(y, x)
                return

    print(-1) #아니면 빠꾸
solve()