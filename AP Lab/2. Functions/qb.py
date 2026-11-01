def shape3():
    for i in range(1, 22):
        for j in range(1, 22):
            if (i == 1 or i == 6 or i == 11 or i == 16 or i == 21) and (j == 1 or j == 6 or j == 11 or j == 16 or j == 21):
                print("+", end=" ")
            elif i == 1 or i == 6 or i == 11 or i == 16 or i == 21:
                print("-", end=" ")
            elif j == 1 or j == 6 or j == 11 or j == 16 or j == 21:
                print("|", end=" ")
            else:
                print(" ", end=" ")
        print("")

shape3()