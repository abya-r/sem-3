def volume_of_cylinder(h , d):
    r = d/2
    return 3.14*r**2*h
h, d = float(input("enter height of cylinder: ")), float(input("enter diameter of cylinder: "))
print("volume of cylinder = ", volume_of_cylinder(h, d))
