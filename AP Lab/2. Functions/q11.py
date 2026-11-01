def prism_area(l, w, h):
    return 2*l*w + 2*w*h + 2*h*l
l, w, h = float(input("enter sides of prism: ")), float(input()), float(input())
print("area of prism = ", prism_area(l, w, h), "sq. units")
