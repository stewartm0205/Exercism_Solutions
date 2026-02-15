""" Module return the value for a resistor color"""
res_color = {"black": 0, "brown": 1, "red": 2, "orange": 3,
             "yellow": 4, "green": 5, "blue": 6, "violet": 7,
             "grey": 8, "white": 9}

def color_code(color):
    """ Function returns the value for a resistor color"""
    return res_color[color]

def colors():
    """ Function returns all the resistor colors"""
    return list(res_color.keys())
