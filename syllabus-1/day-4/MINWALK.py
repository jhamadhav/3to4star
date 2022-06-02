import heapq


def dfs(st, arr):
    costs = [-1 for i in range(len(arr))]
    visited = [0 for i in range(len(arr))]

    q = []
    heapq.heappush(q, (0, st))
    costs[st] = 0

    while(len(q) > 0):
        temp = heapq.heappop(q)
        val = temp[0]
        node = temp[1]

        if(visited[node] == 1):
            continue

        visited[node] = 1
        for i in arr[node]:
            if(visited[i[0]] != 0):
                continue

            if(costs[i[0]] == -1):
                costs[i[0]] = i[1] + val
            else:
                costs[i[0]] = min(costs[i[0]], i[1] + val)
            heapq.heappush(q, (costs[i[0]], i[0]))
    return costs


def solve():
    (n, e) = map(int, input().split())
    (s, v, t) = map(int, input().split())
    s -= 1
    v -= 1
    t -= 1

    arr = [[] for i in range(n)]
    for i in range(e):
        (a, b, c) = map(int, input().split())
        a -= 1
        b -= 1

        arr[a].append((b, c))
        arr[b].append((a, c))

    sCosts = dfs(s, arr)
    vCosts = dfs(v, arr)
    tCosts = dfs(t, arr)

    res = -1
    for i in range(n):
        val = sCosts[i] + vCosts[i] + tCosts[i]
        if(res == -1 or res > val):
            res = val
    print(res)


# testcase
t = int(input())
while(t > 0):
    solve()
    t -= 1
