def quick_algorithm(a, b, c):
    a = a % c
    ans = 1
    while b != 0:
        if b & 1:
            ans = (ans*a) % c
        b >>= 1
        a = (a*a) % c
    return ans


mod = int(1e9 + 7)
t = int(input())
cnt = int(1)
while t != 0:
    t -= 1
    n, k = map(int, input().split(' '))
    pow2 = quick_algorithm(int(2), int(n), mod)
    f = []
    f.append(int(1))
    for i in range(k):
        if i == 0:
            continue
        tmp = f[i - 1] * int(n - i + 1) // int(i)
        f.append(tmp)

    ans = pow2
    for i in f:
        ans = ans - i

    ans %= mod
    print("Case #", end='')
    print(cnt, end='')
    print(": ", end='')
    cnt = cnt + 1
    print(ans)
