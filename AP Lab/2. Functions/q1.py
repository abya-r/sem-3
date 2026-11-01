def simple_interest(p, r, t):
    return p*r*t//100
p, r, t = float(input("enter principal: ")), float(input("enter rate: ")), float(input("enter time: "))
print("simple interest = ", simple_interest(p, r, t))
