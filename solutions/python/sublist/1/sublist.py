"""
This exercise stub and the test suite contain several enumerated constants.

Since Python 2 does not have the enum module, the idiomatic way to write
enumerated constants has traditionally been a NAME assigned to an arbitrary,
but unique value. An integer is traditionally used because it’s memory
efficient.
It is a common practice to export both constants and functions that work with
those constants (ex. the constants in the os, subprocess and re modules).

You can learn more here: https://en.wikipedia.org/wiki/Enumerated_type
"""

# Possible sublist categories.
# Change the values as you see fit.
SUBLIST = 1
SUPERLIST = 2
EQUAL = 3
UNEQUAL = 4


def sublist(list_one, list_two):
    if len(list_one) == 0 and len(list_two) > 0:
        return SUBLIST

    if len(list_one) > 0 and len(list_two) == 0:
        return SUPERLIST 

    if list_one == list_two:
        return EQUAL
    
    if len(list_one) == len(list_two):
        return UNEQUAL

    if len(list_one) <= len(list_two):
        if findsublist(list_one, list_two):  
            return SUBLIST       
    else:
        if findsublist(list_two, list_one):  
            return SUPERLIST 
 
    return UNEQUAL 

def findsublist(list1, list2):
    #print(len(list1),len(list2))
    sp = 0
    j = sp
    i = 0
    while j<len(list2):
        #print(i,j,list1[i],list2[j])
        if list1[i] == list2[j]:
            i += 1
            j += 1
        else:
            sp += 1
            j = sp
            i = 0
        if i >= len(list1):
            return True
    return False

print(findsublist( [3, 4, 5],[0, 1, 2, 3, 4, 5]))        
