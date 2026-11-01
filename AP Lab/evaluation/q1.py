# a user enters the number and you need to find how many odd digits and even digits are there in the number.

#n = abs(int(input("enter a number: ")))
n = int(input("enter a number: "))
odd, even = 0, 0
if n==0:
    even += 1
while n!=0:
    digit = n%10
    if digit%2==0:
        even += 1
    else:
        odd += 1
    n = n // 10
print("no. of odd digits = ", odd)
print("no. of even digits = ", even)
