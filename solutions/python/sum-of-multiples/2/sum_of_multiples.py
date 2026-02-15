def sum_of_multiples(limit, multiples):
    unique_multiples = set()
    for number in range(1,limit):
        for factor in multiples:
                if number % factor == 0:
                   unique_multiples.add(number)
    sum_of_unique_multiples = sum(unique_multiples)
    return sum_of_unique_multiples
