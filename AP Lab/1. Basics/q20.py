a = int(input("enter a: "))
b = int(input("enter b: "))
while (a!=0):
    a, b = b%a, a
print("hcf = ", b)