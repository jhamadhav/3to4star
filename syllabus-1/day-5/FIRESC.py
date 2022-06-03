import sys
sys.setrecursionlimit(10**6)


def dfs(node, arr, visited, cost):
    if(visited[node] == 1):
        return
    visited[node] = 1
    cost[0] += 1
    for i in arr[node]:
        if(visited[i] == 0):
            dfs(i, arr, visited, cost)


def solve():
    (n, e) = map(int, input().split())

    arr = [[] for i in range(n)]
    for i in range(e):
        (a, b) = map(int, input().split())
        a -= 1
        b -= 1
        arr[a].append(b)
        arr[b].append(a)

    res = []
    visited = [0 for i in range(n)]
    for i in range(n):
        cost = [0]
        dfs(i, arr, visited, cost)
        if(cost[0] != 0):
            res.append(cost[0])

    ans = 1
    for i in res:
        ans *= i
        ans %= (int(1e9) + 7)
    print(str(len(res)) + " " + str(ans))


# testcases
t = int(input())
while(t > 0):
    solve()
    t -= 1
