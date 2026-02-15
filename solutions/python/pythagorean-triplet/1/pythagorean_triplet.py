def triplets_with_sum(number):
    triplets=[]
    for a in range(1,number-2):
        #print(a)
        for c in range(number-2*a,a+1,-1):
            b=number-(a+c)
            #print(a,b,c)
            if a+b+c == number and a*a + b*b == c*c:
                #print ('found a triplet',a,b,c)
                triplets.append([a,b,c])
    
    return(triplets)
print(triplets_with_sum(1001))