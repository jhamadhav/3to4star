def topoSort(arr, ls, indegree):
    res = []
    while(len(ls) > 0):
        node = ls[len(ls) - 1]
        ls.pop()

        res.append(node)
        for i in arr[node]:
            indegree[i] -= 1
            if(indegree[i] == 0):
                ls.append(i)
    return res


def solve():
    (n, m) = map(int, input().split())

    (p, q) = map(int, input().split())
    p -= 1
    q -= 1

    arr = [[] for i in range(n)]
    indegree = [0 for i in range(n)]

    for i in range(m):
        (a, b) = map(int, input().split())
        a -= 1
        b -= 1
        arr[a].append(b)
        indegree[b] += 1

    st = []
    for i in range(n):
        if(indegree[i] == 0):
            st.append(i)

    topo = topoSort(arr, st, indegree)
    # print(topo)

    dp = [0 for i in range(n)]
    dp[q] = 1
    for i in range(n-1, -1, -1):
        curr = topo[i]
        for node in arr[curr]:
            dp[curr] += dp[node]
            dp[curr] %= 1000000007
    print(dp[p])


solve()
