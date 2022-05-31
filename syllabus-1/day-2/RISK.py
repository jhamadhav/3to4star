cord = [(-1, 0), (1, 0), (0, -1), (0, 1)]


def isValid(x, y, n, m):
    return (x >= 0 and y >= 0 and x < m and y < n)


def solve():
    (n, m) = map(int, input().split())

    arr = []
    for i in range(n):
        arr.append([i for i in input()])

    res = []
    count = 0
    for i in range(n):
        for j in range(m):
            if(arr[i][j] == '0'):
                continue
            # [i,j]
            q = []
            q.append((j, i))
            arr[i][j] = '0'

            while(len(q) > 0):
                l = len(q)
                while(l > 0):
                    x = q[0][0]
                    y = q[0][1]
                    q.pop(0)

                    count += 1
                    for k in range(4):
                        cx = x + cord[k][0]
                        cy = y + cord[k][1]

                        if(isValid(cx, cy, n, m) and arr[cy][cx] == '1'):
                            arr[cy][cx] = '0'
                            q.append((cx, cy))
                    l -= 1
            res.append(count)
            count = 0
    res.sort(reverse=True)
    # print(res)
    ans = 0
    for i in range(1, len(res), 2):
        ans += res[i]
    print(ans)


t = int(input())
while(t > 0):
    solve()
    t -= 1
