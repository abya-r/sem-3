def prism_volume(l, w, h):
    return l*w*h
l, w, h = float(input("enter sides of prism: ")), float(input()), float(input())
print("volume of prism = ", prism_volume(l, w, h), "cubic units")
