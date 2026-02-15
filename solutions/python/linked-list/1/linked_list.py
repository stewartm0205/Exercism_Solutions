""" Module docstring """
class Node:
    """ Class docstring """
    def __init__(self, value, succeeding=None, previous=None):
        """ function docstring """
        self.val = value
        self.nxt = succeeding
        self.prev = previous


class LinkedList:
    """ Class docstring """
    def __init__(self):
        """ function docstring """
        self.first = None
        self.last = None

    def push(self, value):
        """ function docstring """
        # insert at back
        cur = Node(value)
        cur.prev = self.last
        if self.last is not None:
            self.last.nxt = cur
        if self.first is None:
            self.first = cur
        self.last = cur

    def pop(self):
        """ function docstring """
        # remove from back
        if self.last is not None:
            curnode = self.last
            value = curnode.val
            if self.first == self.last:
                self.first = None
            self.last = curnode.prev
            if self.last is not None:
                self.last.nxt = None
            return value
        return None

    def shift(self):
        """ function docstring """
        # remove from front
        if self.first == self.last:
            self.last = None
        if self.first is not None:
            firstnode = self.first
            value = firstnode.val
            if firstnode.nxt is not None:
                self.first = firstnode.nxt
            return value

    def unshift(self, value):
        """ function docstring """
        # insert in front
        cur = Node(value)
        if self.first is not None:
            self.first.prev = cur
        cur.nxt = self.first
        self.first = cur
        if self.last is None:
            self.last = cur

    def printll(self):
        curnode = self.first
        while curnode is not None:
            print(curnode.val, end="|")
            curnode = curnode.nxt
        print()
lst = LinkedList()
lst.push(10)
lst.push(20)
print(lst.first.val,lst.first.nxt)
lst.printll()
print(lst.pop(), 20)
lst.printll()
lst.push(30)
lst.printll()
print(lst.shift(), 10)
lst.printll()
lst.unshift(40)
lst.printll()
lst.push(50)
lst.printll()
print(lst.shift(), 40)
lst.printll()
print(lst.pop(), 50)
lst.printll()
print(lst.shift(), 30)
lst.printll()
