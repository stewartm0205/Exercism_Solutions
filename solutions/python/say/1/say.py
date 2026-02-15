unit_words = ['zero', 'one','two','three','four','five','six','seven','eight','nine','ten',
                  'eleven','twelve','thirteen','fourteen','fifteen','sixteen','seventeen',
                  'eighteen','nineteen']
ten_words = ['twenty','thirty','forty','fifty','sixty','seventy','eighty','ninthy']
divisors = [1000000000,1000000,1000,100]
big_words = ['billion','million','thousand','hundred']

def say(number):
    phrase = ""

    if number < 0:
        raise ValueError("Value Error")
    if number >= 1000000000000:
        raise ValueError("Value Error")

    if number < 20:
        return unit_words[number]
    return say2(number)

def say2(number):
    phrase = ""
    if number > 99:   
        for i in range(4):

            d = int(number/divisors[i])          
            r = number%divisors[i]
            
            if d > 0:
                phrase = big_words[i]

                lphrase = say2(d)
                
                phrase = lphrase + " " + phrase
                
                if r > 0:
                    rphrase = say2(r)
                    
                    phrase = phrase + " " + rphrase
                    
                return phrase
    else:
        d=int(number/10)
        
        r=number%10
        
        if d >= 1:
            phrase = ten_words[d-2]
            
            if r > 0:
                phrase = phrase + '-' + unit_words[r]               
                return phrase
            else:               
                return phrase


        else:
            phrase = unit_words[r]                    
            return phrase   
    return ""
