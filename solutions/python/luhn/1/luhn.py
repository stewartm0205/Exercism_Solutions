""" Module docstring """
class Luhn:
    """ Class docstring """
    def __init__(self, card_num):
        """ function docstring """
        self.card_num = card_num.replace(" ", "")

    def valid(self):
        """ function docstring """
        s = 0
        di = 1
        if self.card_num == "0" or self.card_num == " 0":
            return False
        for i in range(len(self.card_num)-1, -1, -1):
            if not self.card_num[i].isnumeric():
                return False
            if di % 2 == 0:
                d = int(self.card_num[i]) * 2
                if d > 9:
                    d = d - 9
            else:
                d = int(self.card_num[i])
            s += d
            di += 1
        if s % 10 == 0:
            return True
        return False
