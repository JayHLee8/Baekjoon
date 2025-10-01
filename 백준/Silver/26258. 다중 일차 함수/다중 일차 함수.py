import bisect
import sys
input = sys.stdin.readline

coord_x = []
coord_y = []
for i in range(int(input())):
    x, y = map(float, input().split())
    coord_x.append(x)
    coord_y.append(y)

for i in range(int(input())):
    c = float(input())
    left, right = bisect.bisect_left(coord_x, c), bisect.bisect_right(coord_x, c)
    if left == right:
        left -= 1
    if coord_y[right] - coord_y[left] > 0:
        print(1)
    elif coord_y[right] - coord_y[left] < 0:
        print(-1)
    else:
        print(0)
