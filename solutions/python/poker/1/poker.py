def best_hands(hands):
    bs = 0.0

    for h in hands:
        s = score(h)
        print("hand:",h,"score:",s)
        if s > bs:
            bs = s

    bh = []
    for h in hands:
        if score(h) == bs:
            bh.append(h)

    if len(bh) == 2:
        h0c = sort_cards(bh[0])
        h1c = sort_cards(bh[1])
        for i in range(5):
            if h0c[i] == h1c[i]:
                continue
            elif h0c[i] > h1c[i]:
                return [bh[0]]
            else:
                return [bh[1]]

    return bh

def score(h):

    vc={}
    sc={}
    for c in h.split(" "):
        #print("c:",c)
        if len(c) == 2:
            v=c[0]
            s=c[1]
        else:
            v="T"
            s=c[2]

        if v in vc:
            vc[v]=vc[v]+1
        else:
            vc[v]=1
        
        if s in sc:
            sc[s]=sc[s]+1
        else:
            sc[s]=1

    print (vc)  
    print (sc)

    if str_flush(sc, vc):
        return(800+high_card(vc))

    if of_a_kind(vc) == 4:
        return(700+of_a_kind_ss(vc))   

    if full_house(vc):
        return(600+full_house_ss(vc))   

    if flush(sc):
        return (500+high_card(vc))

    if straight(vc):
        return (400+straight_ss(vc))

    if of_a_kind(vc) == 3:
        return(300+of_a_kind_ss(vc)) 
    
    if two_pairs(vc):
        return(200+two_pairs_ss(vc)) 
 
    if of_a_kind(vc) == 2:
        return(100+of_a_kind_ss(vc)) 

    return high_card(vc)

def card_val(c):
    cards="23456789TJQKA"
    return cards.find(c)+1

def card_val_acelow(c):
    cards="A23456789TJQK"
    return cards.find(c)+1    

def str_flush(sc,vc):
    if len(sc) == 1 and high_card(vc) - low_card(vc) == 4:
        return True
    return False

def of_a_kind(vc):
    c=0
    for k in vc.keys():
        if vc[k] > c:
            c=vc[k]
    return  c  

def of_a_kind_ss(vc):
    s = 0
    for k in vc.keys():
        if vc[k] > 1:
            return 10 * card_val(k) + highest_val_not(vc,k)
            
def highest_val_not(vc,c):
    hv = 0
    for k in vc.keys():
        if k != c and card_val(k) > hv:
            hv = card_val(k)
    return hv

def full_house(vc):
    if len(vc) == 2:
        return True
    return False

def full_house_ss(vc):
    s=0
    for k in vc.keys():
        if vc[k] == 3:
            s += 10 * card_val(k)
        else:
            s += card_val(k)
    return s        

def flush(sc):
    if len(sc) == 1:
        return True
    return False

def  straight(vc):
    if len(vc) == 5 and high_card(vc) - low_card(vc) == 4:
        return True
    if len(vc) == 5 and high_card_acelow(vc) - low_card_acelow(vc) == 4:
        return True
    return False

def straight_ss(vc):
    if high_card_acelow(vc) == 5:
        return 4
    else: 
        return high_card(vc)   

def two_pairs(vc):
    if len(vc) == 3:
        return True
    return False

def two_pairs_ss(vc):
    pi=0
    
    for k in vc.keys():
        if vc[k] == 2 and pi==0:
            p1 = card_val(k)
            pi += 1
        else:    
            if vc[k] == 2 and pi==1:
                p2 = card_val(k)           
    if p1 > p2:
        s = 4*p1+2*p2
    
    if p2 > p1:
        s = 4*p2+2*p1

    if p1 == p2:
        s = 2*p1    

    for k in vc.keys():     
        if vc[k] == 1:
            return s + card_val(k)

def sort_cards(bh):
    print("sort_cards", bh)
    cs=[]
    for c in bh.split(' '):
        cs.append(c[0])
    cs.sort(reverse=True)
    print (cs)
    return cs




def high_card(vc):
    hc = 0
    for k in vc.keys():
        if card_val(k) > hc:
            hc = card_val(k)
    return hc

def low_card(vc):
    lc = 15
    for k in vc.keys():
        if card_val(k) < lc:
            lc = card_val(k)
    return lc  

def high_card_acelow(vc):
    hc = 0
    for k in vc.keys():
        if card_val_acelow(k) > hc:
            hc = card_val_acelow(k)
    return hc

def low_card_acelow(vc):
    lc = 15
    for k in vc.keys():
        if card_val_acelow(k) < lc:
            lc = card_val_acelow(k)
    return lc  

print('best hand=',best_hands(["3S 5H 6S 8D 7H", "2S 5D 6D 8C 7S"]))
