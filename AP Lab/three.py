a = eval(input("enter list: "))
print("original list: ", end=" ")
for i in a:
    print(i, end = " ")
maxm, minm, p, q = a[0], a[0], 0, 0
for i in range(len(a)):
    if a[i]>maxm:
        maxm = a[i]
        p = i
    if a[i]<minm:
        minm = a[i]
        q = i
print()
print("max = ", maxm)
print("min = ", minm)
a[p], a[q] = a[q], a[p]
print("new list:", end=" ")
for i in a:
    print(i, end=" ")
