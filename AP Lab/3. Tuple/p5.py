def solve_puzzle(heads, legs):
    for chickens in range(heads + 1):
        rabbits = heads - chickens
        if (2 * chickens + 4 * rabbits) == legs:
            return (chickens, rabbits)
    
    return ("No solution", "")

heads = int(input("heads-"))
legs = int(input("legs-"))

chickens, rabbits = solve_puzzle(heads, legs)

if chickens == "No solution":
    print("No solution")
else:
    print(chickens, rabbits)
