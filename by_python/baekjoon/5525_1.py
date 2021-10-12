N = int(input())
S = int(input())
STR = input()
answer = 0
ioio = 'I'

for i in range(N) :
    ioio += 'OI'

LPS = [0 for _ in range(len(ioio))]

idx = 0
for i in range(1, len(ioio)) :
    while idx > 0 and ioio[i] != ioio[idx] :
        idx = LPS[idx-1]
    if ioio[i] == ioio[idx] :
        idx += 1
        LPS[i] = idx

sIdx, iIdx = 0, 0
while sIdx < S :
    if STR[sIdx] == ioio[iIdx] :
        iIdx += 1
        sIdx += 1
    else :
        if iIdx == 0 :
            sIdx += 1
        else :
            iIdx = LPS[iIdx-1]

    if iIdx >= len(ioio) :
        answer += 1
        iIdx = LPS[iIdx-1]

print(answer)