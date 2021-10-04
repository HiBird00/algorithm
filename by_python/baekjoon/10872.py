n = int(input())

def f(num) :
    if(num == 1 or num == 0) :
        return 1
    return num*f(num-1)

print(f(n))