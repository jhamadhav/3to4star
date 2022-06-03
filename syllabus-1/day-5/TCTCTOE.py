def solve():
    s = [['_' for i in range(3)] for i in range(3)]

    for i in range(3):
        inp = input()
        for j in range(3):
            s[i][j] = inp[j]

    cx, co, winx, wino = 0, 0, 0, 0
    x, o = 0, 0
    # horizontal
    for i in range(3):
        x, o = 0, 0
        for j in range(3):
            if (s[i][j] == 'X'):
                x += 1
            elif (s[i][j] == 'O'):
                o += 1
        cx += x
        co += o
        if (x == 3):
            winx += 1
        elif (o == 3):
            wino += 1
    # vertical
    for i in range(3):
        x, o = 0, 0
        for j in range(3):
            if (s[j][i] == 'X'):
                x += 1
            elif (s[j][i] == 'O'):
                o += 1
        if (x == 3):
            winx += 1
        elif (o == 3):
            wino += 1

    # left diagonal
    x = 0
    o = 0
    for i in range(3):
        if (s[i][i] == 'X'):
            x += 1
        elif (s[i][i] == 'O'):
            o += 1

    if (x == 3):
        winx += 1
    elif (o == 3):
        wino += 1

    # right diagonal
    x = 0
    o = 0
    for i in range(3):
        if (s[i][2-i] == 'X'):
            x += 1
        elif (s[i][2-i] == 'O'):
            o += 1

    if (x == 3):
        winx += 1
    elif (o == 3):
        wino += 1

    ans = 2
    if ((winx >= 1 and wino >= 1) or not(cx == co or cx == co + 1) or (wino >= 1 and cx == co + 1) or (winx >= 1 and cx == co)):
        ans = 3
    elif ((winx >= 1 or wino >= 1) or (cx + co == 9)):
        ans = 1
    print(ans)

    # testcases
t = int(input())
while(t > 0):
    solve()
    t -= 1
