""" Module docstring """
def rebase(input_base, digits, output_base):
    """ function docstring """
    if input_base < 2:
        raise ValueError("input base must be >= 2")
    if output_base < 2:
        raise ValueError("output base must be >= 2")

    digits.reverse()
    value = 0
    exp = 1
    for digit in digits:
        if digit >= input_base or digit < 0:
            raise ValueError("all digits must satisfy 0 <= d < input base")
        value += digit * exp
        exp *= input_base

    if value == 0:
        return [0]
    result = []
    while value > 0:
        result.append(value % output_base)
        value = value // output_base

    result.reverse()
    return result
