class Allergies(object):
    #score = 0
    allergy_list = ['eggs', 'peanuts', 'shellfish', 'strawberries', 'tomatoes', 'chocolate', 'pollen', 'cats']
    #my_allergies = []

    def __init__(self, score):
        mask = [1,2,4,8,16,32,64,128]
        self.score = score
        self._my_allergies=[]
        s = score
        #print ("---->s=",s)
        for i in range(0,8):
            if mask[i] & score:
                self._my_allergies.append(self.allergy_list[i])
        #print(self.my_allergies)


    def is_allergic_to(self, item):
        return item in set(self._my_allergies)

    @property
    def lst(self):
        return self._my_allergies