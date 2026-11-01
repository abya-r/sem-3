elements = eval(input())
for i in elements:
    if type(i) == list or type(i) == tuple:
        for j in i:
            print(j, end=" ")
    else:
        print(i, end=" ")
print()