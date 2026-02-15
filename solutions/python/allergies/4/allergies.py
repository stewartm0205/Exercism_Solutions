import math
class Allergies(object):
    allergy_list = ['eggs', 'peanuts', 'shellfish', 'strawberries', 'tomatoes', 'chocolate', 'pollen', 'cats']

    def __init__(self, score):
        m = 1
        self.score = score
        self._my_allergies=[]
        s = score
        for i in range(0,len(self.allergy_list)):
            if m & score:
                self._my_allergies.append(self.allergy_list[i])
            m = m * 2

    def is_allergic_to(self, item):
        return item in set(self._my_allergies)

    @property
    def lst(self):
        return self._my_allergies