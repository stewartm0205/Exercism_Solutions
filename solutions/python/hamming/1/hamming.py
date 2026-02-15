def distance(strand_a, strand_b):
    d = 0
    if len(strand_a) != len(strand_b):
        raise ValueError("Value Error")
    for i in range(len(strand_a)):
        if strand_a[i] != strand_b[i]:
            d += 1
    return d

#print(distance("A", "GA"))