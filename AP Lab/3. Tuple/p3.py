print("enter three sides: ")
a, b, c = int(input()), int(input()), int(input())
t = (a, b, c)

if (t[0] + t[1] > t[2]) and (t[0] + t[2] > t[1]) and (t[1] + t[2] > t[0]):
    print("triangle")
else:
    print("not a triangle")