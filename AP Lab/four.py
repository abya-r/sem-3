enrol = []
name = []
print("enter enrollment no.s: ")
for i in range (10):
    a = int(input())
    enrol.append(a)
print("enter names: ")
for i in range (10):
    a = input()
    name.append(a)
a = int(input("enter enrollment no. to find: "))
found = 0
for i in range (10):
    if enrol[i]==a:
        found+=1
        break
if(found!=0):
    print("enrollment no.: ", enrol[i])
    print("name: ", name[i])
else:
    print("-1")
