def largest_product(series, size):
    if series == "" or size < 1 or size > len(series):
        raise ValueError("Value Error")
    maxprod = 0
    for ni in range(len(series) - size + 1):
        prod = 1
        for si in range(size):
            prod *= int(series[ni+si])
        if prod > maxprod:
            maxprod = prod
            mpi = ni
    return maxprod
