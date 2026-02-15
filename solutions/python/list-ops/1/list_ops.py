""" Module doc """

def append(list1, list2):
    """ func doc """
    list1.extend(list2)
    return list1


def concat(lists):
    """ func doc """
    comb_list = []
    for list in lists:
        comb_list.extend(list)
    return comb_list


def filter(function, list):
    """ func doc """
    return [i for i in list if function(i)]


def length(list):
    """ func doc """
    return len(list)


def map(function, list):
    """ func doc """
    return [function(i) for i in list]


def foldl(function, list, initial):
    """ func doc """
    result = initial
    for i in list:
        result = function(result, i)

    return result


def foldr(function, list, initial):
    """ func doc """
    result = initial
    list.reverse()
    for i in list:
        result = function(i, result)

    return result

def reverse(list):
    """ func doc """
    list.reverse()
    return list
