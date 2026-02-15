""" Module docstring"""

def largest(min_factor, max_factor):
    """Given a range of numbers, find the largest palindromes which
       are products of two numbers within that range.

    :param min_factor: int with a default value of 0
    :param max_factor: int
    :return: tuple of (palindrome, iterable).
             Iterable should contain both factors of the palindrome in an arbitrary order.
    """
    largest_pp = 0
    if min_factor > max_factor:
        raise ValueError("min must be <= max")
    for factor1 in range(max_factor, min_factor-1, -1):
        for factor2 in range(max_factor, min_factor-1, -1):
            if str(factor1 * factor2) == str(factor1 * factor2)[::-1]:
                if factor1 * factor2 > largest_pp:
                    result = (factor1 * factor2, [[factor1, factor2]])
                    largest_pp = factor1 * factor2
                elif factor1 * factor2 == largest_pp:
                    factors = result[1]
                    factors.append([factor1, factor2])
                    result = (result[0], factors)
            if factor1 * factor2 < largest_pp:
                break

    if largest_pp > 0:
        return result
    return (None, [])



def smallest(min_factor, max_factor):
    """Given a range of numbers, find the smallest palindromes which
    are products of two numbers within that range.

    :param min_factor: int with a default value of 0
    :param max_factor: int
    :return: tuple of (palindrome, iterable).
    Iterable should contain both factors of the palindrome in an arbitrary order.
    """
    smallest_pp = min_factor * max_factor

    if min_factor > max_factor:
        raise ValueError("min must be <= max")
    for factor1 in range(min_factor, max_factor+1):
        for factor2 in range(min_factor, max_factor+1):
            if str(factor1 * factor2) == str(factor1 * factor2)[::-1]:
                if factor1 * factor2 < smallest_pp:
                    result = (factor1 * factor2, [[factor1, factor2]])
                    smallest_pp = factor1 * factor2
                elif factor1 * factor2 == smallest_pp:
                    factors = result[1]
                    factors.append([factor1, factor2])
                    result = (result[0], factors)
            if factor1 * factor2 > smallest_pp:
                break

    if smallest_pp < min_factor * max_factor:
        return result
    return (None, [])
