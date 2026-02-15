
class Matrix:
   
    def __init__(self, matrix_string):
        matrix_list=[]
        r=0
        for row_str in matrix_string.split('\n'):
            r=r+1
            matrix_list.append([])
            c=0
            for col_str in row_str.split(' '):
                c=c+1
                matrix_list[r-1].append(int(col_str))
        self.r=r
        self.c=c
        self.values = matrix_list

    def row(self, index):
        return(self.values[index-1])
        

    def column(self, index):
        col = []
        for row in range(self.r):
            col.append(self.values[row][index-1])
        return(col)


