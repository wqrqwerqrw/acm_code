import sys

for line in sys.stdin:
    line = line.strip()
    line = line.split(',')
    nums = list(map(int, line))
    nums.sort()
    print(nums[len(nums) // 2])
