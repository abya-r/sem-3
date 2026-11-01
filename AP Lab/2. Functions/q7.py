def fahrenheit_to_celsius(f):
    return 5/9*(f-32)
f = float(input("enter temperature in fahrenheit: "))
print("temperature in celsius = ", fahrenheit_to_celsius(f))