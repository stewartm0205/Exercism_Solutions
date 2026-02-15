def convert(input_grid):
    template =  [
                " _     _  _     _  _  _  _  _ ",
                "| |  | _| _||_||_ |_   ||_||_|",
                "|_|  ||_  _|  | _||_|  ||_| _|",
                "                              ",
    ]

    if len(input_grid)%4 != 0:
        raise ValueError("ValueError")
    
    if len(input_grid[0])%3 != 0:
        raise ValueError("ValueError")   

    num=""
    for rs in range(int(len(input_grid)/4)):
        #print("rs:",rs)
        l=int(len(input_grid[0])/3)

        for n in range(l):       
            #print("l:",n)
            row = extract(input_grid[rs*4:rs*4+4],n)    
            #print("row=",row)
            match = False
            for i in range(10):  

                if row == extract(template,i):
                    match = True
                    num += str(i)
            if not match:
                num += "?" 
        if rs <  int(len(input_grid)/4)-1:         
            num +=','
    return(num)
     
def extract(pattern,i):
    output=[]
    for r in range(4):
        output.append(pattern[r][i*3:i*3+3])
    return(output)
    
