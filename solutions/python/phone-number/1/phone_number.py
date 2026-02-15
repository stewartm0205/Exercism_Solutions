import re
class PhoneNumber:
    def __init__(self, number):
        pm = re.match("\+?(1?)[\-. ]?\\(?([2-9][0-9]{2})\\)?[. ]*([2-9][0-9]{2})[\-. ]*([0-9]{4}) *$", number)
        self.number=''

        if pm is None:
            raise ValueError('bad telephone number')


        for g in pm.groups():
            #print (g)
            self.number=self.number+g


        print('len',len(self.number))
        if len(self.number) == 11:
            self.area_code=self.number[1:4]
            self.number = self.number[1:]
        elif len(self.number) == 10:
            self.area_code=self.number[0:3]
        else:
            self.area_code=''


    def pretty(self):
        if len(self.number) == 10:
            return('(' + self.area_code+')-'+self.number[3:6]+'-'+self.number[6:])
        else:
            return(self.number[1:4]+'-'+self.number[4:])      

#pn=PhoneNumber("321234567890")
#print(pn.pretty())
#print(PhoneNumber("223.456.7890").number)
