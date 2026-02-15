""" converts a number into pling plang Plong"""
def convert(number):
    """ converts a number into pling plang Plong"""
    result = ""
    if number % 3 == 0:
        result += "Pling"

    if number % 5 == 0:
        result += "Plang"

    if number % 7 == 0:
        result += "Plong"

    if result == "":
        result = str(number)

    return result
