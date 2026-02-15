
class ConnectGame:

    def __init__(self, board):
        self.gb = []
        i=0
        for r in board.split('\n'):
            s=r.strip()
            s='.'*i+s
            i+=1
            self.gb.append(s)
        self.nr=len(self.gb)
        self.nc=len(self.gb[self.nr-1])

    def get_winner(self):
        # Find starting nodes
        output = ""
        if len(self.gb) == 1:
            return self.gb[0]
        for x in range(len(self.gb[0])-1):
            if self.gb[0][x] == 'O':
                output = self.searchpath(0,x,'O')
        
        if output == "":
            for y in range(self.nr):
                for x in range(len(self.gb[y])):
                    if self.gb[y][x] != '.':
                        break
                if self.gb[y][x] == 'X':
                    output = self.searchpath(y,x,'X')      
        return output

    def searchpath(self,y,x,who):
        if who == 'O':
            moves=[[1,1],[-1,1],[2,0],[-2,0],[1,-1],[-1,-1]]
        else:
            moves=[[2,0],[1,1],[1,-1],[-1,1],[-1,-1],[-2,0]]
        self.gb[y]=self.gb[y][0:x]+"U"+self.gb[y][x+1:]

        for move in moves:

            nx=x+move[0]
            ny=y+move[1]

            if nx >= 0 and ny >= 0 and ny < self.nr and nx < len(self.gb[ny]):

                if (who == "O" and self.gb[ny][nx] == who and ny == self.nr - 1) or \
                    (who == "X" and self.gb[ny][nx] == who and nx == len(self.gb[ny])-1):

                    return who
                else:
                    if self.gb[ny][nx] == who:
 
                        return self.searchpath(ny,nx,who)

        return ''
