def compound_interest(p, r, t):
    return p*((1 + r/100)**t) - p
p, r, t = float(input("enter principal: ")), float(input("enter rate: ")), float(input("enter time: "))
print("compound interest = ", compound_interest(p, r, t))
