""" Module to give a list of prime numbers from 2 to limit"""
def primes(limit):
    """ Function to give a list of prime numbers from 2 to limit"""
    if limit == 1:
        return []

    primes_list = [2]
    for num in range(3, limit + 1, 2):
        for pri_num in primes_list:
            if num % pri_num == 0 or pri_num * pri_num > num:
                break

        if num % pri_num != 0:
            primes_list.append(num)

    return primes_list
