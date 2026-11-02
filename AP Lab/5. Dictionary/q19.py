primes = {}
for num in range(50, 101):
    is_prime = True
    for i in range(2, int(num ** 0.5) + 1):
        if num % i == 0:
            is_prime = False
            break
    if is_prime:
        digit_sum = sum(int(digit) for digit in str(num))
        primes[num] = digit_sum

print(primes)