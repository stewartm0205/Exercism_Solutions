""" Module docstring """
rom_cnv = {1000:"M", 900: "CM", 500: "D", 400: "CD",
           100: "C", 90:"XC", 50: "L", 40: "XL",
           10: "X", 9: "IX", 5:"V", 4: "IV", 1:"I"}
def roman(number):
    """ function docstring """
    result = ""
    while number > 0:
        for key, value in rom_cnv.items():
            while key <= number:
                result += value
                number = number - key
    return result
    