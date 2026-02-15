""" This module contains a function to encrpyt
    text strings.
"""
import math
def cipher_text(plain_text):
    """
    Input parms: a plain_text string.
    Returns: an encrypted strings that contains a set of standard length
             substrings separate by spaces.
    """
    if len(plain_text) == 0:
        return ""

    norm_text = plain_text.lower()
    for c in " .,@!#%":
        norm_text = norm_text.replace(c,"")
    print (norm_text)
    c=math.ceil(math.sqrt(len(norm_text)))
    r=math.ceil(len(norm_text)/c)
    print("len=",len(norm_text),"c=",c,"r=",r)
    groups = ""
    for i in range(r):
        if c>r:
            print (norm_text[i*c:i*c+r+1])
            groups += norm_text[i*c:i*c+r+1]
        else:
            print (norm_text[i*c:i*c+r])
            groups += norm_text[i*c:i*c+r]
    groups += ((c * r) - len(groups)) * " "

    out = ""
    for i in range(c):
        for j in range(r):
            print (groups[j*c+i])
            out += groups[j*c+i]
        out +=" "

    out = out[:-1]
    return out;
#print(cipher_text("Chill out."))
print(cipher_text("If man was meant to stay on the ground, god would have given us roots."))
