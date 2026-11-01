l = eval(input("enter list: "))
adj = 0
for i in range (len(l)-1):
    if l[i+1] == l[i]:
        adj+=1
print(adj)