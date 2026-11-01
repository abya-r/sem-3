max = 0  ####m k
print("enter 10 numbers: ")
for i in range(10):
    a = int(input())
    if a%2!=0 and a>max:
        max = a
if max==0:
    print("no odd numbers entered")
else:
    print("largest odd number entered = ", max)