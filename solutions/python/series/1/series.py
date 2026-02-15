def slices(series, length):
    if len(series) < length:
        raise ValueError("Value Error")
    if length < 1:
        raise ValueError("Value Error")
    if len(series) < 1:
        raise ValueError("Value Error")
    s=[]
    for i in range(0,len(series)-length+1):
        c=series[i:i+length]
        s.append(c)
    return s

