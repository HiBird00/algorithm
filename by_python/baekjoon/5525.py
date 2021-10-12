N = int(input())
S = int(input())
STR = input()

ioio = 'I'
for i in range(N) :
    ioio += 'OI'

answer = 0
   
temp = ''
for i in range(len(STR)) :
    if not temp :
        if STR[i] == 'I' : 
            temp += STR[i]
        continue
 
    if temp[-1] != STR[i] :
        temp += STR[i]
    else :
        if STR[i] == 'I' :
            temp = STR[i]
        else : temp = ''
        continue
    
    if temp == ioio :
        answer += 1
        temp = temp[2:]

print(answer)
        
        
        