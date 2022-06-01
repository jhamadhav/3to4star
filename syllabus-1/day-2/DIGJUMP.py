def solve():
    s = input().strip()

    temp = ""
    i = 0
    while(i < len(s)):
        temp += s[i]

        if(i+1 < len(s) and s[i] == s[i+1]):
            while(i+1 < len(s) and s[i] == s[i+1]):
                i += 1
        else:
            i += 1
    s = temp
    # print(s)

    n = len(s)
    if(n == 1):
        print(0)
        return

    m = [[] for i in range(11)]
    for i in range(n):
        num = int(s[i])
        m[num].append(i)
    # print(m)

    # visited array
    visited = [0 for i in range(n)]

    count = 0
    q = []
    q.append(0)
    visited[0] = 1
    while(len(q) > 0):
        l = len(q)
        while(l > 0):
            node = q[0]
            q.pop(0)

            if(node == n-1):
                print(count)
                return

            if(node - 1 >= 0 and visited[node-1] == 0):
                q.append(node - 1)
                visited[node - 1] = 1

            if(node + 1 < n and visited[node+1] == 0):
                q.append(node + 1)
                visited[node + 1] = 1

            num = int(s[node])
            for i in m[num]:
                if(visited[i] == 0):
                    q.append(i)
                    visited[i] = 1
            l -= 1

        count += 1

    print(count)


solve()
