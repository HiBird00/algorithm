import sys

n = int(input())
n_list = []

for i in range(n) :
    n_list.append(int(sys.stdin.readline()))

def devide(arr) :
    if len(arr) == 1 :
        return arr
    # divide
    mid = len(arr) // 2
    left = devide(arr[:mid])
    right = devide(arr[mid:])

    #conquer
    s_list = []
    i, j = [0,0]
    while(i < len(left) and j < len(right)) :
        if(left[i] > right[j]) :
            s_list.append(right[j])
            j += 1
        else :
            s_list.append(left[i])
            i += 1

    if(i < len(left)) :
        s_list += left[i:]
    elif(j < len(right)) :
        s_list += right[j:]

    return s_list

ret = devide(n_list)
for i in ret :
    print(i)
