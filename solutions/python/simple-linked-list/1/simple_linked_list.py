""" Module docstring """
import copy
class Node:
    """ Class docstring """
    def __init__(self, value):
        """ Function docstring """
        self.data = value
        self.nxt = None

    def value(self):
        return self.data

    def next(self):
        return self.nxt


class LinkedList:
    """ Class docstring """
    def __init__(self, values=[]):
        self.first = None
        self._nxt = self.first
        for v_i in range(len(values)):
            self.push(values[v_i])


    def __len__(self):
        count = 0
        next = self.first
        while next is not None:
            count += 1
            next = next.nxt
        return count

    def head(self):
        if self.first is None:
            raise EmptyListException("The list is empty.")
        return self.first

    def push(self, value):
        curr = Node(value)
        curr.nxt = self.first
        self.first = curr

    def pop(self):
        if self.first is None:
            raise EmptyListException("The list is empty.")
        curr = self.first
        self.first = curr.nxt
        return curr.data

    def reversed(self):

        rev = LinkedList()
        while self.first is not None:
            value = self.pop()
            rev.push(value)
        return rev

    def __iter__ (self):
        return copy.deepcopy(self)

    def __next__(self):
        if self.first is not None:
            return self.pop()

        raise StopIteration


class EmptyListException(Exception):
    """ Class docstring """
    def __init__(self, message):
        self.message = message
