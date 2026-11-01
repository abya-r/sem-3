l = eval(input("enter list: "))
print("original list: ", l)
min, max, iax, iin = l[0], l[0], 0, 0
for i in range(len(l)):
    if l[i]>max:
        max = l[i]
        iax = i
    if l[i]<min:
        min = l[i]
        iin = i
print("max = ", max)
print("min = ", min)
l[iax], l[iin] = l[iin], l[iax]
print("updated list: ", l)