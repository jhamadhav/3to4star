def solve():
    (n, b) = map(int, input().split(' '))

    if(b == 0 and n != 2):
        print("YES")
        for i in range(2, n+1):
            print("1 " + str(i))
        return

    if(n == 2 and b == 1):
        print("YES")
        print("1 2")
        return

    if(4*b > n or (n == 2 and b == 0)):
        print("NO")
        return

    x = 2*b + 2
    print("YES")
    for i in range(2, x+1):
        print(str(i - 1) + " " + str(i))

    for i in range(x+1, n+1):
        print(str(x-1) + " " + str(i))


t = int(input())
while(t):
    solve()
    t -= 1
