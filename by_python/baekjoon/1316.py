c = int(input())
ret = 0
for i in range(c) :
    str = input()
    exist = []
    status = True
    for j in range(len(str)) :
        if(j==0) :
            exist.append(str[j])
            continue
        if(exist[-1] != str[j]) :
            if(str[j] in exist) :
                status = False
                break
            exist.append(str[j])

    if(status) : ret += 1

print(ret)


