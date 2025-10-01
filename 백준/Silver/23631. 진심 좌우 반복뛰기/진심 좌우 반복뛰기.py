import sys

def alt_sum(t: int) -> int:
    """1-2+3-4+...±t 의 값 (O(1) 연산)"""
    # t가 짝수면 -t//2, 홀수면 (t+1)//2
    return (-(t // 2)) if t % 2 == 0 else ((t + 1) // 2)

def solve_case(N: int, K: int):
    D = N - 1
    if D == 0:
        return 0, 'R'

    # K*m*(m+1)//2 >= D 를 만족하는 최소 m 찾기 (O(1) 근사 후 보정)
    # 근의 공식에서 m^2 + m - 2D/K >= 0 → m = ceil((-1 + sqrt(1 + 8D/K))/2)
    if K == 0:
        return 0, 'R'
    from math import isqrt

    # 8*D//K가 매우 클 수 있으니 int로 처리
    val = 1 + 8 * D // K
    sqrt_val = isqrt(val)
    if sqrt_val * sqrt_val < val:
        sqrt_val += 1
    m = ((-1 + sqrt_val) + 1) // 2  # 올림
    while K * m * (m + 1) // 2 < D:
        m += 1

    Sm = K * m * (m + 1) // 2
    S_prev = K * (m - 1) * m // 2

    if Sm == D:
        x = K * alt_sum(m)
        facing = 'R' if (m + 1) % 2 == 1 else 'L'
        return x, facing
    else:
        rem = D - S_prev
        x_prev = K * alt_sum(m - 1)
        dir_m = 1 if m % 2 == 1 else -1
        x = x_prev + dir_m * rem
        facing = 'R' if dir_m == 1 else 'L'
        return x, facing

def main():
    input = sys.stdin.readline
    T = int(input())
    out_lines = []
    for _ in range(T):
        N, K = map(int, input().split())
        x, d = solve_case(N, K)
        out_lines.append(f"{x} {d}")
    print("\n".join(out_lines))

if __name__ == "__main__":
    main()
