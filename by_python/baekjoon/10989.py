import sys

n = int(input())
count = [0] * 10001

for i in range(n) :
    count[int(sys.stdin.readline())] += 1

for i in range(10001) :
    if(count[i] != 0) :
        print(f'{i}\n'*count[i], end="")