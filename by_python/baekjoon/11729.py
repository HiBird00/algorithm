# aux_pos : 보조기둥
ret = []

def hanoi(N, from_pos, to_pos, aux_pos) :
    if N == 1 : 
        ret.append([from_pos, to_pos])
        return
    
    # 원반 n-1개를 aux_pos로 이동(to_pos를 보조 기둥으로)
    hanoi(N-1, from_pos, aux_pos, to_pos)

    # 마지막 원반 목적지로 
    ret.append([from_pos, to_pos])

    # aux_pos로 옮겻던거 목적지로 이동
    hanoi(N-1, aux_pos, to_pos, from_pos)
    

n = int(input())
hanoi(n, 1, 3, 2)
print(len(ret))
for i in range(len(ret)) : 
    print(ret[i][0], ret[i][1])