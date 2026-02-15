""" Module docstring """
def encode(message, rails):
    """ function docstring """
    rail = []
    for ri in range(rails):
        rail.append(" " * len(message))
    ri = 0
    dr = 1
    for ti in range(len(message)):
        rail[ri] = rail[ri][:ti] + message[ti] + rail[ri][ti+1:]
        ri += dr
        if ri == rails:
            dr = -1
            ri = rails - 2
        elif ri == -1:
            dr = 1
            ri = 1
    ec = ''
    for ri in range(rails):
        for ti in range(len(message)):
            if rail[ri][ti] != ' ':
                ec += rail[ri][ti]
    return ec


def decode(encoded_message, rails):
    """ function docstring """
    rail = []
    for ri in range(rails):
        rail.append("-" * (len(encoded_message)+5))
    dc_len = len(encoded_message)
    sl=dc_len//( 2 * rails - 2)
    si = []
    nc = []

    for ri in range(rails):
        if ri == 0:
            si.append(0)
            nc.append(sl)
            if dc_len % rails != 0:
                nc[0] += 1
        elif ri < rails - 1:
            si.append(sum(nc))
            nc.append(2*sl)
        else:
            si.append(sum(nc))
            nc.append(sl)
    if sum(nc) < dc_len:
        si[2] += 1
    dc = ''
    ri = 0
    dr = 1
    for ti in range(len(encoded_message)):
        rail[ri]= rail[ri][:ti] + encoded_message[si[ri]] + rail[ri][ti+1:]
        dc += rail[ri][ti]
        si[ri] += 1
        ri = ri + dr
        if ri >= rails:
            dr = -1
            ri = rails - 2
        elif ri < 0:
            dr = 1
            ri = 1

    return dc
