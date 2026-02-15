def sum_of_multiples(limit, multiples):
    mn = []
    for n in range(1,limit):
        for m in multiples:
            if n not in mn:
                if n % m == 0:
                    mn.append(n)
    sm = sum(mn)
    return sm
