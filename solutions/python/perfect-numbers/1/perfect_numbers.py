def classify(number):
    if number < 1:
        raise ValueError("Value Error")
    aliquot_sum = sum(factors(number))
    if aliquot_sum == number:
        return("perfect")
    elif aliquot_sum > number:
        return("abundant")
    else: 
        return("deficient")

def factors(number):
    return([i for i in range(1,int(number / 2)+1) if number % i == 0])

