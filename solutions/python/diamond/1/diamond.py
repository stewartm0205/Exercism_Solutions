""" Module docstring """
import string
def rows(letter):
    """ function docstring """
    lp = string.ascii_uppercase.index(letter)
    dia = []
    for li in range(lp+1):
        if li == 0:
            line = " " * (lp - li) + string.ascii_uppercase[li] + " " * (lp - li)
        else:
            line = " " * (lp - li) + string.ascii_uppercase[li]
            line = line + " " * (2 * li -1) + string.ascii_uppercase[li] + " " * (lp - li)
        dia.append(line)
    for li in range(lp-1, -1, -1):
        if li == 0:
            line = " " * (lp - li) + string.ascii_uppercase[li] + " " * (lp - li)
        else:
            line = " " * (lp - li) + string.ascii_uppercase[li]
            line = line + " " * (2 * li - 1) + string.ascii_uppercase[li] + " " * (lp - li)
        dia.append(line)
    return dia
