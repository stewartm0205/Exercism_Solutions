""" Module doc string """
res_val = {"black": 0, "brown": 1, "red": 2,
           "orange": 3, "yellow": 4, "green": 5,
           "blue": 6, "violet": 7, "grey": 8, "white": 9}

def value(colors):
    """ function doc string"""
    return res_val[colors[0]] * 10 + res_val[colors[1]]
