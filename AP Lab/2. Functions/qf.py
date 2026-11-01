def print_numbers():
    choice = int(input("Enter 1 for Ascending or 2 for Descending: "))

    if choice == 1:
        i = 1
        while i <= 10:
            print(i)
            i += 1
    elif choice == 2:
        i = 10
        while i >= 1:
            print(i)
            i -= 1
    else:
        print("Invalid choice!")


print_numbers()