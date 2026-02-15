import string
import random
class Robot:
    robots=[]
    def __init__(self):
        self.name = self.gen_name()

    def gen_name(self):    
        unique_name = False
        while not unique_name:
            name=random.choice(string.ascii_uppercase) + \
                    random.choice(string.ascii_uppercase) + \
                    random.choice('0123456789') + random.choice('0123456789') + \
                    random.choice('0123456789')
            #print("gen_name",name)
            if name not in self.robots:
                unique_name = True
                self.robots.append(name)
        return(name)        


    def reset(self):
        self.name=self.gen_name()
        #print("gen_name=",self.gen_name())
        #print(self.name)

#r=Robot()
##print (r.name)
#r.reset()
#print(r.name)