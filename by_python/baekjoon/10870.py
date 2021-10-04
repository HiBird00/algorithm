n = int(input())

def p(num) :
    if(num == 0 or num == 1 ) :
        return num
    return p(num-1)+p(num-2)

print(p(n))