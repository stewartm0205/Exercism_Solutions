def steps(number):
    if number <= 0:
        raise ValueError("Value Error")
    s=0
    while(number!=1):
        s+=1
        if number % 2 == 0:
            number /= 2
        else:
            number = 3 * number + 1
        #print("number=",number)
    return(s)
print(steps(1000000))