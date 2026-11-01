def area_of_cylinder(h , d):
    r = d/2
    return 2*3.14*r*(r+h)
h, d = float(input("enter height of cylinder: ")), float(input("enter diameter of cylinder: "))
print("area of cylinder =", area_of_cylinder(h, d))
