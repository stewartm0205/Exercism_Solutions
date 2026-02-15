from math import sqrt
def prime_factors(natural_number):
    pf = []
    factor=2
    while (factor <= natural_number):
        if natural_number % factor == 0:
            pf.append(factor)
            natural_number = natural_number / factor
        else:
            factor += 1
    return pf
