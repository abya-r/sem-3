cart = eval(input())
product = [i[0] for i in cart]
price = [i[1] for i in cart]
total_cost = [i[1]*i[2] for i in cart]

maxPrice = price[0]
for p in price:
    if p>maxPrice:
        maxPrice = p
ind = price.index(maxPrice)
print(f"Most expensive item by total cost: {product[ind]}({total_cost[ind]})")

"""
print("Items with total cost >1000: ", end="") 
for cost in total_cost:
    if cost>1000:
        ind = total_cost.index(cost)
        print(f"{product[ind]}", end = " ")
print("")
"""

total_bill = sum(total_cost)
discount=0
print(f"Initial Total Bill: {total_bill}", end=", ")
if total_bill > 50000:
    discount = 0.1*total_bill
    print(f"Discount applied (10%): {discount}")
else:
    print("No discount applied.")
print(f"Final Payable Amount: {total_bill-discount}")
    
