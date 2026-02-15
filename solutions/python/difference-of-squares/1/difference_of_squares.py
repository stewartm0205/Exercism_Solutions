def square_of_sum(count):
    return (sum(i+1 for i in range(count)))**2 

def sum_of_squares(count):
    return sum((i+1)**2 for i in range(count))

def difference(count):
    return square_of_sum(count) - sum_of_squares(count)
