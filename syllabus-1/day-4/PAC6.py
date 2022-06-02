import heapq


def dfs(st, arr, costs):
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


def solve():
    (n, m, r, x, y) = map(int, input().split())
    x -= 1
    y -= 1

    arr = [[] for i in range(n)]
    for i in range(r):
        (a, b, c) = map(int, input().split())
        a -= 1
        b -= 1

        arr[a].append((b, c))
        arr[b].append((a, c))

    costs = [-1 for i in range(n)]
    dfs(x, arr, costs)

    if(costs[y] > m):
        print("died")
        return
    print("alive " + str(costs[y]))


solve()
