def flatten(iterable):
    result=[]
    for item in iterable:
        if type(item) == list:
            for subitem in flatten(item):
                result.append(subitem)
        elif (type(item) == tuple or type(item) == set or type == dict): 
            if item:
                result.append(item)
        elif item is not None:
            result.append(item)

    return result
