l = eval(input())
f = []

m = []
maxm=0
for i in l:
    if i in m:
        continue
    f.append((i, l.count(i)))
    if l.count(i)>maxm:
        maxm = l.count(i)
    m.append(i)
print(f)


once = []
count = 0
print("Most frequent numbers are ", end="")
for i in f:
    if i[1]==maxm:
        print(i[0], end = " ")
    if i[1]==1:
        count = 1
        once.append(i[0])
print(f"and their Frequency = {maxm}")

print("Numbers occurring exactly once:", end=" ")

if len(once)==0:
    print("None")
else:
    for i in once:
        print(i, end=" ")
