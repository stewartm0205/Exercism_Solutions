import re
def find_first_bracket(input_string):
    for i in range(len(input_string)):
        if input_string[i] in ["(","{","["]:
            return i
        if input_string[i] in [")",'}',']']:
            return -1
    return -2    

def find_closing_bracket(bbp,open_bracket,close_bracket,input_string):
    bc = 1
    print("cb",close_bracket)
    for i in range(bbp+1,len(input_string)):
        if input_string[i] == open_bracket:
            bc=bc+1
        if input_string[i] == close_bracket:
            bc=bc-1
        if bc == 0:
            return i
    return -1

def is_paired(input_string):

    bbp = find_first_bracket(input_string)

    if bbp == -1:
        return False
    if bbp == -2:
        return True 

    open_bracket = input_string[bbp]
    if open_bracket == '(':
        close_bracket = ')'
    elif open_bracket == '{':
        close_bracket = '}'
    else:
        close_bracket = ']'

    cbp = find_closing_bracket(bbp, open_bracket, close_bracket, input_string)  
   
    if cbp == -1:
        return False
    
    if bbp+1 == cbp:
        if cbp == len(input_string)-1:
            return True 
        else:
            return is_paired(input_string[cbp+1:])

    if cbp+1 < len(input_string):
        return is_paired(input_string[bbp+1:cbp]) and is_paired(input_string[cbp+1:])
    elif bbp+1 < cbp:
        return is_paired(input_string[bbp+1:cbp])
    else:
        return True
