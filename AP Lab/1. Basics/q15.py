n = int(input("enter number: "))
new, position = 0, 1
for i in range(5):
    new = new + (n%10+1)%10*position
    position = position*10
    n = n//10
print("new number = ", new)