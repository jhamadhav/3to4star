cord = [(-1, 0), (1, 0), (0, -1), (0, 1), (1, 1), (-1, -1), (1, -1), (-1, 1)]


def isValid(x, y, n, m):
    return (x >= 0 and y >= 0 and x < n and y < m)


def solve():
    (r, c, k) = map(int, input().split())
    r -= 1
    c -= 1

    visited = [[0 for i in range(8)] for i in range(8)]
    visited[r][c] = 1

    q = []
    q.append((r, c))

    count = 1
    while(len(q) > 0 and k > 0):
        l = len(q)
        while(l > 0):
            node = q[0]
            q.pop(0)

            for i in cord:
                cr = node[0] + i[0]
                cc = node[1] + i[1]

                if(isValid(cr, cc, 8, 8) and visited[cr][cc] == 0):
                    q.append((cr, cc))
                    visited[cr][cc] = 1
                    count += 1
            l -= 1
        k -= 1

    print(count)


# testcase
t = int(input())
while(t > 0):
    solve()
    t -= 1
