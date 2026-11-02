import math

odd = {}
count = 0
num = 1
while count < 50:
    odd[num] = math.log2(num)
    num += 2
    count += 1

print(odd)