""" Module docstring """
def find(search_list, value):
    """ Function docstring"""
    if search_list == []:
        raise ValueError("value not in array")
    low = 0
    high = len(search_list)
    middle = (high - low) // 2
    if high == 1 and search_list[0] == value:
        return 0

    while search_list[middle] != value and high > low + 1:
        if value < search_list[middle]:
            high = middle
        if value > search_list[middle]:
            low = middle
        middle = low+(high - low) // 2

    if search_list[middle] != value:
        raise ValueError("value not in array")

    return middle
    