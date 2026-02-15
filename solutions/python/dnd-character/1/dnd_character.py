""" Module docstring """
import random

class Character:
    """ Class docstring """
    def __init__(self):
        """ Function docstring """

        self.strength = self.calc_score()
        self.dexterity = self.calc_score()
        self.constitution = self.calc_score()
        self.intelligence = self.calc_score()
        self.wisdom = self.calc_score()
        self.charisma = self.calc_score()
        self.hitpoints = 10 + (self.constitution - 10) // 2

    def calc_score(self):
        scores = []
        for i in range(4):
            scores.append(random.randint(1, 6))
            scores.sorted()

        return sum(scores[0:3])