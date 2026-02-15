import random
""" Module docstring """
def private_key(p):
    """ function docstring """
    return random.randrange(1, p)


def public_key(p, g, private):
    """ function docstring """
    return pow(g, private) % p


def secret(p, public, private):
    """ function docstring """
    return pow(public, private) % p
