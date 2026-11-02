start_year = int(input("Enter starting year: "))
leap_years = []
year = start_year

while len(leap_years) < 15:
    if (year%4==0 and year%100!=0) or (year% 400==0):
        leap_years.append(year)
    year += 1

print(leap_years)