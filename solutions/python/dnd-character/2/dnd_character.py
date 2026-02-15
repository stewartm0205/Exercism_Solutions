""" Module docstring """
import random

class Character:
    """ Class docstring """
    def __init__(self):
        """ Function docstring """

        self.strength = self.ability()
        self.dexterity = self.ability()
        self.constitution = self.ability()
        self.intelligence = self.ability()
        self.wisdom = self.ability()
        self.charisma = self.ability()
        self.hitpoints = 10 + modifier(self.constitution)
    def ability(self):
        """ Function docstring """

        scores = []
        for _ in range(4):
            scores.append(random.randint(1, 6))
            scores.sort()

        return sum(scores[0:3])

def modifier(constitution):
    """ Function docstring """
    return (constitution - 10) // 2
    