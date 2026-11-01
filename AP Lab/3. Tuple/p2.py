gems = ('Emerald', 'Ivory', 'Jasper', 'Ruby', 'Garnet')
price = (1760, 2119, 1599, 3920, 3999)

g = input("enter gems to purchase: ").split()
q = input("enter quantity: ").split()

bill = 0

for j in range(len(g)):
    found = False
    for i in range(len(gems)):
        if gems[i] == g[j]:
            bill += price[i] * int(q[j])
            found = True
            break
    if not found:
        bill = -1
        break

if bill > 30000:
    bill = bill - bill * 0.05

print("bill =", bill)