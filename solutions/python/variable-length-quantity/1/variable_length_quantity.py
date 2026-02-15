def encode(numbers):
    out=[]
    for num in numbers:
        if num == 0:
            out.append(0)
        else:    
            bits = format(num,"032b")
            zs=True
            b=bits[0:4]
            if b != '0000':
                b='1000'+b
                zs=False
                out.append(int(b,2))
            for i in range(4):
                b = bits[7*i+4:7*(i+1)+4]
                if b != '0000000' or not zs:
                    if i<3:
                        b='1'+b
                    else:
                        b='0'+b    
                    zs=False
                    out.append(int(b,2))
         
    return out    


def decode(bytes_):
    if len(bytes_) == 1 and bytes_[0] >= 0x80:
        raise ValueError("Value Error")
    out=[]
    wordbits = ""    
    for b in bytes_:
     
       bytebits=format(b,"08b")
       wordbits += bytebits[1:]
       if bytebits[0] == '0':
           out.append(int(wordbits,2))
           wordbits = ""
    
    if len(wordbits) > 0:
        out.append(int(wordbits,2))      

    return out

           