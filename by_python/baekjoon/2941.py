ret = 0
str = input()
i = 0
while i < len(str) :
    if (i < len(str)-2) :
        if(str[i:i+3] == 'dz=') :
            i += 2
    if (i < len(str)-1) : 
        ch = str[i:i+2]
        if(ch == 'c=' or ch == 'c-' or ch == 'd-' or ch == 'lj' or ch == 'nj' or ch == 's=' or ch == 'z=') :
            i += 1
    ret += 1
    i+=1

print(ret)