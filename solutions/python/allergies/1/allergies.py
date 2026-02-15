class Allergies(object):
    score = 0
    allergy_list = ['eggs', 'peanuts', 'shellfish', 'strawberries', 'tomatoes', 'chocolate', 'pollen', 'cats']
    my_allergies = []

    def __init__(self, score):
        self.score = score
        self.my_allergies=[]
        s = score
        #print ("---->s=",s)
        for i in range(0,8):
            r = s % 2
            s = s // 2;
            if r == 1:
                self.my_allergies.append(self.allergy_list[i])
        #print(self.my_allergies)


    def is_allergic_to(self, item):
        return item in set(self.my_allergies)

    @property
    def lst(self):
        return self.my_allergies