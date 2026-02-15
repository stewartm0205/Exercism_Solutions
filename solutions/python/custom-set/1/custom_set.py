""" Module docstring """
class CustomSet:
    """ Class docstring """
    def __init__(self, elements=[]):
        """ Function docstring """
        self.elements = []
        for element in elements:
            if element not in self.elements:
                self.elements.append(element)

    def isempty(self):
        """ Function docstring """
        return (len(self.elements) == 0)

    def __contains__(self, element):
        """ Function docstring """
        return element in self.elements

    def issubset(self, other):
        """ Function docstring """
        if self.elements == []:
            return True
        for element in self.elements:
            if element not in other.elements:
                return False
        return True


    def isdisjoint(self, other):
        """ Function docstring """
        for element in self.elements:
            if element in other.elements:
                return False
        for element in other.elements:
            if element in self.elements:
                return False
        return True

    def __eq__(self, other):
        """ Function docstring """
        if len(self.elements) == len(other.elements):
            for element in self.elements:
                if element not in other.elements:
                    return False
            return True
        return False

    def add(self, element):
        """ Function docstring """
        if element not in self.elements:
            self.elements.append(element)

    def intersection(self, other):
        """ Function docstring """
        inter=CustomSet()
        for element in self.elements:
            if element in other.elements:
                inter.elements.append(element)
        return inter

    def __sub__(self, other):
        """ Function docstring """
        result = CustomSet()
        for element in self.elements:
            if element not in other.elements:
                result.add(element)
        return result

    def __add__(self, other):
        """ Function docstring """
        result = CustomSet()
        for element in self.elements:
            result.add(element)
        for element in other.elements:
            result.add(element)
        return result
        