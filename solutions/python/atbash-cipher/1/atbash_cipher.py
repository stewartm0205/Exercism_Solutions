alphabet = 'abcdefghijklmnopqrstuvwxyz'
revalpha = 'zyxwvutsrqponmlkjihgfedcba'

def encode(plain_text):
     
    i=0
    ec = ''
    for l in plain_text.lower():
        if l not in " ,.":
            if  l < 'a' or l > 'z': 
                ec+=l
            else:
                ec+=revalpha[alphabet.index(l)]
            i+=1
            if i > 4:
                i = 0
                ec+=' '
    return ec.rstrip() 

def decode(ciphered_text):

    dc = ''
    for l in ciphered_text:
        if  l < 'a' or l > 'z': 
            if l != ' ':
                dc+=l
        else: 
            dc+=alphabet[revalpha.index(l)]
    return dc
