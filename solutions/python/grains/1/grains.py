def on_square(integer_number):
    if integer_number < 1 or integer_number > 64:
        raise ValueError("Value Error")

    return 2**(integer_number-1)


def total_after(integer_number):
    if integer_number < 1 or integer_number > 64:
        raise ValueError("Value Error")
    s = 0
    if integer_number < 64:
        for i in range(integer_number):
              s += on_square(i)
    else:
        s = 18446744073709551615
    return s
