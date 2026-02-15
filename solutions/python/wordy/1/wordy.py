import re
def answer(question):

    # What is <number>?
    r = re.match(r"^What is (-?[0-9]*)\?$", question)
    print("p1-match=",r)
    if r != None:
        print("p1:")
        return int(r.group(1))

    # what is <number> <operator> <number>?
    r = re.match(r"^What is (-?[0-9]*) (plus|minus|multiplied by|divided by) (-?[0-9]*)\?$", question)
    print("p2-match=",r)
    if r != None:
        print("p2:")
        print (r.groups())
        a = int(r.group(1))
        b = int(r.group(3))
        if r.group(2) == 'plus':
            return a + b
        elif r.group(2) == 'minus':
            return a - b
        elif r.group(2) == 'multiplied by':
            return a * b
        elif r.group(2) == 'divided by':
            return a / b    
        else:
            raise ValueError("Value Error")    

    # what is <number> <operator> <number> <operator> <number>?
    r = re.match(r"^What is (-?[0-9]*) (plus|minus|multiplied by|divided by) (-?[0-9]*) (plus|minus|multiplied by|divided by) (-?[0-9]*)\?$", question)
    print("p3-match=",r)
    if r != None:
        print("p2:")
        print (r.groups())
        a = int(r.group(1))
        b = int(r.group(3))
        c = int(r.group(5))
        if r.group(2) == 'plus':
            d = a + b
        elif r.group(2) == 'minus':
            d = a - b
        elif r.group(2) == 'multiplied by':
            d = a * b
        elif r.group(2) == 'divided by':
            d = a / b    
        else:
            raise ValueError("Value Error")  

        if r.group(4) == 'plus':
            return d + c
        elif r.group(4) == 'minus':
            return d - c
        elif r.group(4) == 'multiplied by':
            return d * c
        elif r.group(4) == 'divided by':
            return d / c  
        else:
            raise ValueError("Value Error")  
    raise ValueError("Value Error") 

print(answer("What is 5?"))

