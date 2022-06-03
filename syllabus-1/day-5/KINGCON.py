import sys
sys.setrecursionlimit(10**6)


def dfs(arr, node, visited, disc, low, ap, timer, parent):
    children = 0

    timer += 1
    disc[node] = timer
    low[node] = timer

    visited[node] = 1
    for i in arr[node]:
        if(visited[i] == 0):
            children += 1
            dfs(arr, i, visited, disc, low, ap, timer, node)

            low[node] = min(low[node], low[i])

            if(parent != -1 and low[i] >= disc[node]):
                ap[node] = 1
        elif(i != parent):
            low[node] = min(low[node], disc[i])

    if(parent == -1 and children > 1):
        ap[node] = 1


def solve():
    (n, m, k) = map(int, sys.stdin.readline().split())

    arr = [[] for i in range(n)]
    for i in range(m):
        (a, b) = map(int, sys.stdin.readline().split())
        arr[a].append(b)
        arr[b].append(a)

    visited = [0 for i in range(n)]
    disc = [0 for i in range(n)]
    low = [0 for i in range(n)]
    ap = [0 for i in range(n)]

    dfs(arr, 0, visited, disc, low, ap, 0, -1)

    cost = 0
    for i in range(n):
        if(ap[i] == 1):
            cost += k
    print(cost)


# testcases
t = int(sys.stdin.readline())
while(t > 0):
    solve()
    t -= 1
