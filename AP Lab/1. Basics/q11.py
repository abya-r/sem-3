print("Enter marks in 5 subjects: ")
total = 0
for i in range(5):
    mark = int(input(""))
    total = total+mark
print("Percentage = ", total/5)