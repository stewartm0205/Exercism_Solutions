import string

def rotate(text, key):
    abc=string.ascii_lowercase
    ABC=string.ascii_uppercase
    output = ""
    for l in text:
        if l in abc:
            output += abc[(abc.index(l)+key)%26]
        elif l in ABC:
            output += ABC[(ABC.index(l)+key)%26]
        else:
            output += l    

    return output
