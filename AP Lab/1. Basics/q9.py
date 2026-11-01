a = int(input("Enter a: "))
b = int(input("Enter b: "))
c = int(input("Enter c: "))
greatest = a
if b>greatest:
    greatest = b
if c>greatest:
    greatest = c
print("greatest = ", greatest)