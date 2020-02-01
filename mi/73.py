import sys


def do(line):
    nums = list(map(int, line))


for line in sys.stdin:
    line = line.strip()
    line = line.split(',')
    do(line)
