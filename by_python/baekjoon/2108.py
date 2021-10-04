from collections import Counter
import sys

N  = int(sys.stdin.readline())
n_list = []

for i in range(N) :
    num = int(sys.stdin.readline())
    n_list.append(num)

# 평균
print(round(sum(n_list)/N))

# 중앙값
n_list.sort()
print(n_list[N//2])

# 최빈값
count = Counter(n_list).most_common();
print(count[0][0] if len(count) == 1 or count[0][1] != count[1][1] else count[1][0])

# 범위
print(n_list[-1] - n_list[0])