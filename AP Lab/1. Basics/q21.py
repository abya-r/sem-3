a = int(input("enter a: "))
b = int(input("enter b: "))

x, y = a, b
while x != 0:
    x, y = y % x, x
hcf = y

lcm = (a * b) // hcf
print("lcm = ", lcm)