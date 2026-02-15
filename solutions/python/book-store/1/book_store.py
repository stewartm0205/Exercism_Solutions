""" Model docstring """
def total(basket):
    """ function docstring """
    if basket is None or basket == []:
        return 0

    discount = [1, 0.95, 0.9, 0.8, 0.75]
    min_cost = 0


    combos = find_combos(len(basket))
    for combo in combos:
        tbasket = list(basket)
        cost = 0
        for n in combo:
            set = find_set(tbasket,n)
            if set == []:
                break
            cost += len(set) * 800 * discount[len(set) - 1]
            tbasket = remove_set(tbasket, set)
        while len(tbasket) > 0:
            set = find_set(tbasket,5)
            if set == []:
                break
            cost += len(set) * 800 * discount[len(set) - 1]
            tbasket = remove_set(tbasket, set)

        if min_cost == 0:
            min_cost = cost
        if cost < min_cost:
            min_cost = cost

    return min_cost

def find_combos (nbooks):
    combos = []
    b=[5,4,3]
    for i in range(0,3):
        for j in range(i,3):
            for k in range(j,3):
                combo=[]
                if b[i] <= nbooks:
                    combo.append(b[i])
                if b[i] + b[j] <= nbooks:
                    combo.append(b[j])
                if b[i] + b[j] + b[k] <= nbooks:
                    combo.append(b[k])
                combos.append(combo)

    return combos

def find_set (basket, n):
    book_count = {}
    max_books = 0
    for book in basket:
        if book not in book_count.keys():
            book_count[book] = 1
        else:
            book_count[book] += 1
        if book_count[book] > max_books:
             max_books = book_count[book]

    bkset = []
    while len(bkset) < n and max_books > 0:
        for (book, count) in book_count.items():
            if count == max_books and book not in bkset:
                bkset.append(book)
                if len(bkset) == n:
                    return bkset
        max_books -= 1

    return bkset

def remove_set(basket, set):
    result = basket
    for book in set:
        basket.remove(book)
    return basket
