def reverse(input=''):
    out=""
    for i in range(len(input)):
        out += input[-(i+1)]
    return out