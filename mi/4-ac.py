import sys
def do(numstr):
    nums = list(map(int, numstr))
    bit = 0
    for x in nums:
        bit = bit | (1 << int(x))
    bit = bin(bit)[2:]
    bit = bit.split('0')
    maxn = -1
    for x in bit:
        if len(x) > maxn:
            maxn = len(x)
    print(maxn)

for line in sys.stdin:
    line = line.strip()
    numstr = line.split(',')
    do(numstr)
