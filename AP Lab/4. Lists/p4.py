enrol = eval(input("enter enrolment numbers: "));
name = input("enter names: ").split(",")
target = int(input("enter enrollment no. to search for: "))
found = False
for i in range(len(enrol)):
    if enrol[i] == target:
        print("Student found: ")
        print(enrol[i], name[i])
        found = True
        break
if not found:
    print(-1)