""" Module docstring """
def prime(number):
    """ function docstring """
    if number == 0:
        raise ValueError('there is no zeroth prime')
    n_pr = [2]
    nxt = 3
    while len(n_pr) < number:
        i = 0
        while n_pr[i] * n_pr[i] < nxt:
            if nxt % n_pr[i] == 0:
                break
            i += 1
        if n_pr[i] * n_pr[i] > nxt:
            n_pr.append(nxt)
        nxt += 2
    return n_pr[-1]
