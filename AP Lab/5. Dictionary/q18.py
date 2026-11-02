import math

odd1 = {}
count = 0
num = 1
while count < 50:
    odd1[num] = math.log2(num)
    num += 2
    count += 1
print(odd1)

def get_log2(n):
    low = 0.0
    high = float(n)
    for _ in range(60):
        mid = (low + high) / 2
        if 2.0 ** mid < n:
            low = mid
        else:
            high = mid
    return low

odd2 = {}
count = 0
num = 1
while count < 50:
    odd2[num] = get_log2(num)
    num += 2
    count += 1

print(odd2)