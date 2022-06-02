def solve():
    (n, e) = map(int, input().split())

    nodeVal = [int(i) for i in input().split()]

    arr = {}
    for i in range(e):
        (a, b) = map(int, input().split())
        a -= 1
        b -= 1

        temp = abs(nodeVal[b] - nodeVal[a])
        if str(temp) not in arr.keys():
            arr[str(temp)] = []

        if(temp == 0):
            continue

        if(nodeVal[b] >= nodeVal[a]):
            arr[str(temp)].append((a, b))
        else:
            arr[str(temp)].append((b, a))

    dp = [0 for i in range(n)]
    temp = [0 for i in range(n)]
    for j in sorted(arr.keys()):
        for k in arr[str(j)]:
            temp[k[1]] = 0

        for k in arr[str(j)]:
            temp[k[1]] = max(temp[k[1]], dp[k[0]] + 1)

        for k in arr[str(j)]:
            dp[k[1]] = max(temp[k[1]], dp[k[1]])

    res = 0
    for i in range(n):
        res = max(res, dp[i])
    print(res + 1)


# testcases
t = int(input())
while(t > 0):
    solve()
    t -= 1
