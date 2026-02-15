def saddle_points(matrix):
    
    sp = set()
    if len(matrix) > 0:
        ncol = len(matrix[0])
        
        for r in range(len(matrix)):
            if len(matrix[r]) != ncol:
                raise ValueError("Value Error")
            for c in range(len(matrix[r])):
                if matrix[r][c] == max(matrix[r]): 
                    col = column(matrix,c)
                    if matrix[r][c] == min(col):
                        sp.add((r, c))
    return sp  

def column(matrix,col):
    return [matrix[r][col] for r in range(len(matrix))]
