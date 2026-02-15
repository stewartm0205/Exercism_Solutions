""" Module docstring """
def spiral_matrix(size):
    """ Fuction docstring """
    matrix=[]
    r = 0
    c = 0
    # fill up matrix with zeros
    for r in range(size):
        matrix.append([])
        for c in range(size):
            matrix[r].append(0)

    r = 0
    c = 0
    dr = 'C+'
    for num in range(1,size*size+1):
        matrix[r][c] = num
        if dr == 'C+':
            if c + 1 == size or matrix[r][c + 1] != 0:
                dr = 'R+'
                r += 1
            else:
                c += 1
        elif dr == 'R+':
            if r + 1 == size or matrix[r + 1][c] != 0:
                dr = 'C-'
                c = c - 1
            else:
                r += 1
        elif dr == 'C-':
            if c - 1 < 0 or matrix[r][c - 1] != 0:
                dr = 'R-'
                r = r - 1
            else:
                c = c - 1
        else: # R-
            if r - 1 < 0 or matrix[r - 1][c] != 0:
                dr = 'C+'
                c += 1
            else:
                r = r - 1
    return matrix
