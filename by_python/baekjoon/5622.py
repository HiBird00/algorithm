dial = [
    [ 'A', 'B', 'C' ],
    [ 'D', 'E', 'F' ],
    [ 'G', 'H', 'I' ],
    [ 'J', 'K', 'L' ],
    [ 'M', 'N', 'O' ],
    [ 'P', 'Q', 'R', 'S' ],
    [ 'T', 'U', 'V' ],
    [ 'W', 'X', 'Y', 'Z' ]
]
s_list = list(input())
ret = 0

for i in range(len(s_list)) :
    for j in range(len(dial)) : 
        if(s_list[i] in dial[j]) : ret += j+3
            
print(ret)
