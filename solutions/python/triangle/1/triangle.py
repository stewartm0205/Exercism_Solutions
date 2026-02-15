def equilateral(sides):
    if sides[0] == 0 or sides[1] == 0 and sides[2] == 0:
        return False 

    if (max(sides) == sides[0] and (sides[1] + sides[2]) < sides[0]) or \
       (max(sides) == sides[1] and (sides[0] + sides[2]) < sides[1]) or \
       (max(sides) == sides[2] and (sides[0] + sides[1]) < sides[2]):
        return False

    if sides[0] == sides[1] and sides[1] == sides[2]:
        return True
    return False


def isosceles(sides):
    if sides[0] == 0 or sides[1] == 0 and sides[2] == 0:
        return False 

    if (max(sides) == sides[0] and (sides[1] + sides[2]) < sides[0]) or \
       (max(sides) == sides[1] and (sides[0] + sides[2]) < sides[1]) or \
       (max(sides) == sides[2] and (sides[0] + sides[1]) < sides[2]):
        return False  

    if sides[0] == sides[1] or sides[1] == sides[2] or sides[0] == sides[2]:
        return True
    return False


def scalene(sides):
    if sides[0] == 0 or sides[1] == 0 and sides[2] == 0:
        return False  

    if (max(sides) == sides[0] and (sides[1] + sides[2]) < sides[0]) or \
       (max(sides) == sides[1] and (sides[0] + sides[2]) < sides[1]) or \
       (max(sides) == sides[2] and (sides[0] + sides[1]) < sides[2]):
        return False    
        
    if sides[0] != sides[1] and sides[1] != sides[2] and sides[0] != sides[2]:
        return True
    
    return False
