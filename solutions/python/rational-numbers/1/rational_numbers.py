""" Module docstring """
from __future__ import division

import math

class Rational:
    """ Class docstring """
    def __init__(self, numer, denom):
        """ function docstring """

        self.numer = int(numer)
        self.denom = int(denom)
        if self.numer == 0:
            self.denom = 1
        if self.numer == self.denom:
            self.numer = 1
            self.denom = 1
        if  self.denom < 0:
            self.numer = -1 * self.numer
            self.denom = -1 * self.denom
        if self.numer % self.denom == 0:
            self.numer = self.numer / self.denom
            self.denom = 1
        if self.denom < 0 and self.denom % self.numer == 0:
            self.denom = abs(self.denom / self.numer)
            self.numer = -1

        if self.numer > 0 and self.denom > 0 and self.denom % self.numer == 0:
            self.denom = self.denom / self.numer
            self.numer = 1

        g = math.gcd(int(abs(self.numer)), int(abs(self.denom)))
        if g > 1:
            self.numer = self.numer / g
            self.denom = self.denom / g

    def __eq__(self, other):
        """ function docstring """
        if type(other) != Rational:
            return False
        return self.numer == other.numer and self.denom == other.denom

    def __repr__(self):
        """ function docstring """
        return '{}/{}'.format(self.numer, self.denom)

    def __add__(self, other):
        """ function docstring """
        numer = self.numer * other.denom + other.numer * self.denom
        denom = self.denom * other.denom
        return Rational(numer, denom)

    def __sub__(self, other):
        """ function docstring """
        self.numer = self.numer * other.denom - other.numer * self.denom
        self.denom = self.denom * other.denom
        if self.numer == 0:
            self.denom = 1
        return self

    def __mul__(self, other):
        """ function docstring """
        numer = self.numer * other.numer
        denom = self.denom * other.denom
        return Rational(numer, denom)

    def __truediv__(self, other):
        """ function docstring """
        numer = self.numer * other.denom
        denom = other.numer * self.denom
        return Rational(numer, denom)

    def __abs__(self):
        """ function docstring """
        self.numer = abs(self.numer)
        self.denom = abs(self.denom)
        return self

    def __pow__(self, power):
        """ function docstring """
        if power > 0:
            self.numer = pow(self.numer, power)
            self.denom = pow(self.denom, power)
            return self

        if power < 0:
            self.denom = pow(self.numer, abs(power))
            self.numer = pow(self.denom, abs(power))
            return self

        if power == 0:
            self.numer = 1
            self.denom = 1
            return self

    def __rpow__(self, base):
        """ function docstring """
        return pow(base, self.numer/self.denom)
