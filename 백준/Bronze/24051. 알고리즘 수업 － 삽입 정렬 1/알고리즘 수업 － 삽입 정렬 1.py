import sys

def solve():
    input = sys.stdin.readline
    N, K = map(int, input().split())
    A = list(map(int, input().split()))
    count = 0
    for i in range(1, N):
        key = A[i]
        j = i - 1
        left, right = 0, i - 1
        while left <= right:
            mid = (left + right) // 2
            if A[mid] < key:
                left = mid + 1
            else:
                right = mid - 1
        for k in range(i - 1, left - 1, -1):
            A[k + 1] = A[k]
            count += 1
            if count == K:
                print(A[k + 1])
                return
        if left != i:
            A[left] = key
            count += 1
            if count == K:
                print(A[left])
                return
    
    print(-1)

solve()