c = int(input())
board = []
for i in range(5):
    w = input()
    board.append(list(w))

n = int(input())
words = []
for i in range(n):
    word = input()
    words.append(word)

xPos = [1, 1, 0, -1, -1, -1, 0, 1]
yPos = [0, 1, 1, 1, 0, -1, -1, -1]

def hasWord(x, y, word):
    # base case
    if x < 0 or x > 4 or y < 0 or y > 4:
        return False
    
    if board[y][x] != word[0]:
        return False

    if len(word) == 1:
        return True
    
    for i in range(8):
        if hasWord(x+xPos[i], y+yPos[i], word[1:]):
            return True
    return False

for word in words:
    check = False
    for i in range(5):
        for j in range(5):
            if hasWord(i,j,word):
                check = True
                break
        if check:
            print(word,"YES")
            break
    if not check:
        print(word, "NO")  
