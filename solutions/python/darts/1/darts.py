""" Module docstring """
import math
def score(x, y):
    """ Module docstring """
    if math.sqrt(x * x + y * y) <= 1:
        return 10
    elif math.sqrt(x * x + y * y) <= 5:
        return 5
    elif math.sqrt(x * x + y * y) <= 10:
        return 1

    return 0
