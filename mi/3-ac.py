import sys

for line in sys.stdin:
    line = line.strip()
    a = line.split('-')
    inta = int(a[0])
    intb = int(a[1])
    print(inta - intb)
