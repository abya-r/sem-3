def shape1():
    for i in range(1, 7):
        for j in range(1, 7):
            if (i==1 or i==6) and (j==1 or j==6):
                print("+", end=" ")
            elif i==1 or i==6:
                print("-", end=" ")
            elif j==1 or j==6:
                print("|", end=" ")
            else:
                print(" ", end=" ")
        print("")

def shape2():
    for i in range(1, 12):
        for j in range(1, 12):
            if (i==1 or i==6 or i==11) and (j==1 or j==6 or j==11):
                print("+", end=" ")
            elif i == 1 or i == 6 or i == 11:
                print("-", end=" ")
            elif j == 1 or j == 6 or j == 11:
                print("|", end=" ")
            else:
                print(" ", end=" ")
        print("")

shape1()
shape2()

