""" Model docstring """
def decode(string):
    """ function docstring """
    dc_str = ''
    num = ''
    for ch in string:
        if ch in "0123456789":
            num += ch
        else:
            if len(num) > 0:
                dc_str += ch * int(num)
                num = ''
            else:
                dc_str += ch
    return dc_str


def encode(string):
    """ function docstring """
    ec_str = ''
    pch = ''
    count = 1
    for ch in string:
        if ch == pch:
            count += 1
        else:
            if count > 1:
                ec_str += str(count) + pch
                pch = ch
                count = 1
            else:
                ec_str += pch
                pch = ch
    if count > 1:
        ec_str += str(count) + pch
    else:
        ec_str += pch
    return ec_str
