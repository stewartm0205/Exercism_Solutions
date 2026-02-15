def annotate(minefield):
    # Function body starts here
    adjsq=[[-1,0],[-1,-1],[0,-1],[1,-1],[1,0],[1,1],[0,1],[-1,1]]
    output=[]
    if len(minefield) == 0:
        return output
    nr = len(minefield)
    nc = len(minefield[0])
    for y in range(nr):
        row=minefield[y]
        if len(minefield[y]) != nc:
            raise ValueError("Value Error")
        for x in range(nc):
            if minefield[y][x] != " " and minefield[y][x] != "*":
                raise ValueError("Value Error")
            if minefield[y][x] == " ":
                c = 0
                for dxy in adjsq:
                    if x+dxy[0] >= 0 and x+dxy[0] < nc and \
                       y+dxy[1] >= 0 and y+dxy[1] < nr :
                       if minefield[y+dxy[1]][x+dxy[0]] == "*":
                           c += 1
                if c > 0:
                    row=insch(row,str(c),x)
        output.append(row)
             
    return(output)

def insch (s,ch,pos):
    l=len(s)
    if pos < l-1:
        return s[0:pos]+ch+s[pos+1:]
    else:
        return s[0:pos]+ch

