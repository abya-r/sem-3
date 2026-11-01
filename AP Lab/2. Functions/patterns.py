def shape1(n):
    for i in range(1, n+1):
        for j in range(1, n+1):
            if (i==1 or i==n) and (j==1 or j==n):
                print("+", end=" ")
            elif i==1 or i==n:
                print("-", end=" ")
            elif j==1 or j==n:
                print("|", end=" ")
            else:
                print(" ", end=" ")
        print("")

def shape2(n):
    for i in range(1, n+1):
        for j in range(1, n+1):
            if (i==1 or i==n//2 or i==n) and (j==1 or j==n/2 or j==n):
                print("+", end=" ")
            elif i == 1 or i == n//2 or i == n:
                print("-", end=" ")
            elif j == 1 or j == n//2 or j == n:
                print("|", end=" ")
            else:
                print(" ", end=" ")
        print("")

def shape3(n):
    for i in range(1, n+1):
        for j in range(1, n+1):
            if (i == 1 or i == n//2 or i == n//4 or i == 3*n//4 or i == n) and (j == 1 or j == n//4 or j == n//2 or j == 3*n//4 or j == n):
                print("+", end=" ")
            elif i == 1 or i == n//4 or i == n//2 or i == 3*n//4 or i == n:
                print("-", end=" ")
            elif j == 1 or j == n//4 or j == n//2 or j == 3*n//4 or j == n:
                print("|", end=" ")
            else:
                print(" ", end=" ")
        print("")

def square_with_diagonals(n):
    for i in range(1, n+1):
        for j in range(1, n+1):
            if (i==1 and j==1) or (i==1 and j==n) or (i==n and j==n) or (i==n and j==n):
                print("+", end=" ")
            elif i==1 or i==n:
                print("-", end=" ")
            elif j==1 or j==n:
                print("|", end=" ")
            elif i==j or i+j==n+1:
                print("*", end=" ")
            else:
                print(" ", end=" ")
        print("")


def triangle(n):
    for i in range(1, n+1):
        for j in range(1, n):
            if i>n//2:
                if (i==j or i+j==n+1) or i==n:
                    print("*", end=" ")
                else:
                    print(" ", end=" ")
        if i>n//2:
            print("")
n = int(input("enter n: "))
shape1(n)
shape2(n)
shape3(n)
square_with_diagonals(n)
triangle(n)
