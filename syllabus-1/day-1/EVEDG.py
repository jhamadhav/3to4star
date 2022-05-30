def solve():
    (n, e) = map(int, input().split())

    bucketArr = [1 for i in range(0, n+1)]
    edgeCount = [0 for i in range(0, n+1)]

    u, v = -1, -1
    for i in range(1, e+1):
        (a, b) = map(int, input().split())
        if(u == v):
            u, v = a, b
        edgeCount[a] += 1
        edgeCount[b] += 1

    # if no of edges is even
    if(e % 2 == 0):
        print(1)
        for i in range(1, n+1):
            print(bucketArr[i], end=" ")
        print()
        return

    # if edge count is odd
    # if a node with odd edge count exist
    node = -1
    for i in range(1, n+1):
        if(edgeCount[i] % 2 == 1):
            node = i
            bucketArr[i] = 2
            break

    if(node != -1):
        print(2)
        for i in range(1, n+1):
            print(bucketArr[i], end=" ")
        print()
        return

    # else we select 1 edge and it's connected one
    for i in range(1, n+1):
        if(i == u):
            bucketArr[i] = 2
        elif(i == v):
            bucketArr[i] = 3

    print(3)
    for i in range(1, n+1):
        print(bucketArr[i], end=" ")
    print()


t = int(input())
while(t):
    solve()
    t -= 1
