from math import sqrt
def prime_factors(natural_number):
    pf = []
    i=2
    r=natural_number
    while (i <= r):
        if is_prime(i):
            if r % i == 0:
                pf.append(i)
                r = int(r / i)
            else:
                i += 1
        else:
            i += 1
    return pf

def is_prime(natural_number):
    for i in range(2, int(sqrt(natural_number))):
        if natural_number % i == 0:
            return False
    return True

print(prime_factors(9))

