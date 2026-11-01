a = int(input("enter an integer: "))  #####
found = 0
for i in range(abs(a)):
    if i*i*i==abs(a):
        found = 1
        break
    i += 1
if found==0:
    print("the number is not perfect cube")
else:
    if a>0:
        print("the number is a perfect cube of", i)
    else:
        print("the number is a perfect cube of", -i)