def square_with_diagonals():
    for i in range(1, 10):
        for j in range(1, 10):
            if (i==1 and j==1) or (i==1 and j==9) or (i==9 and j==9) or (i==9 and j==1):
                print("+", end=" ")
            elif i==1 or i==9:
                print("-", end=" ")
            elif j==1 or j==9:
                print("|", end=" ")
            elif i==j or i+j==10:
                print("*", end=" ")
            else:
                print(" ", end=" ")
        print("")
square_with_diagonals()


def triangle2():
    for i in range(1, 26):
        for j in range(1, 26):
            if i>=13:
                if (i==j or i+j==26) or i==25:
                    print("*", end=" ")
                else:
                    print(" ", end=" ")
        if i>=13:
            print("")
triangle2()
