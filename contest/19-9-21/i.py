t = int(input())
while t > 0:
    t = t - 1
    str = input()
    lis = str.split(" ")
    a = int(lis[0])
    b = int(lis[1])
    c = int(lis[2])
    d = int(lis[3])
    print(a + b + c + d)