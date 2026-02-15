def rectangles(strings):
    rc=[]
    v=[]
    r=0
    for string in strings:
        c=0
        for ch in string:
            if ch == '+':
                rc.append((r,c))
                v.append((r,c))
            elif ch == "|":
                v.append((r,c))
            c += 1
        r += 1
    #print ('rc=',rc)
    #print ('v=',v)
    #print ("")
    c = 0
    if len(rc) == 0:
        return 0
    for fe in rc:
        c += find_rectanges(fe,rc,v)
 
    return c

def find_rectanges(ule,rc,v):

    edges=find_edges(ule,rc)
    #print("ule=",ule,"edges=",edges)

    c = 0
    for ex in edges:
        if ex[0] == ule[0]: 
            for ey in edges:
                if ey[1] == ule[1]:
                    for ce in rc:
                        if ce[1] > ule[1] or ce[0] > ule[0]:
                            if ce != ule and (ce[0] == ey[0] and ce[1] == ex[1]):
                                #print("ule:",ule,"ex:",ex,"ey:",ey,"ce:",ce)
                                # check if edges are complete
                                if (ey[0] == ule[0]+1 or (ule[0]+1,ule[1]) in v) and \
                                   (ce[0] == ex[0]+1 or (ex[0]+1, ex[1]) in v):
                                    #print("rectangle")
                                    c += 1

    return c


def find_edges(ule,rc):
    edges=[]
    for e in rc:
        if (e[0] == ule[0] and e[1] > ule[1]) or (e[1] == ule[1] and e[0] > ule[0]):
            if (e[0] == ule[0] or e[1]==ule[1]):
                edges.append(e)

    return(edges)        
