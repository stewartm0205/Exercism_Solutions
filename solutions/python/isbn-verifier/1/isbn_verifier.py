def verify(isbn):
    sum = 0
    di = 0
    if len(isbn) == 0:
        return False
    isbn = isbn.lower()
    for ni in range(len(isbn)):
        n = isbn[ni]
        if n in "0123456789":
            sum += (10-di)*int(n)
            di += 1
            #print(ni,di,int(n),sum)
        elif n == "x":
            sum += (10-di)*10
        elif n != "-":
            return False
    if sum % 11 == 0:
        return True
    else:
        return False

print (verify('3-598-21508-8'))