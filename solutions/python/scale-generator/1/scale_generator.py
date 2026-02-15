class Scale:
    
    def __init__(self, tonic):
        self.scale_sharp=['A', 'A#', 'B', 'C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#']
        self.scale_flat=['A', 'Bb', 'B', 'C', 'Db', 'D', 'Eb', 'E', 'F', 'Gb', 'G', 'Ab']
        #self.sharp_tonic=['G', 'D', 'A', 'E', 'B', 'F#', 'e', 'b', 'f#', 'c#']
        self.flat_tonic=['F', 'Bb', 'Eb', 'Ab', 'Db', 'Gb', 'd', 'g', 'c', 'f', 'bb', 'eb'] 
        self.tonic = tonic
        #print('tonic',tonic)

    def chromatic(self):
        scale = self.scale_sharp
        
        if self.tonic in self.flat_tonic:
            scale = self.scale_flat

        if self.tonic[0].islower():
            if len(self.tonic) == 1:
                si=scale.index(self.tonic[0].upper())
            else:
                 si=scale.index(self.tonic[0].upper() + self.tonic[1])   
        else:    
            si=scale.index(self.tonic)
    
        j=0
        s=[]
        while (si+j < len(scale)):
            #print ('j:',j,'si+j',si+j)
            s.append(scale[si+j])
            j += 1

        i=0
        while (i < si):
            s.append(scale[i])
            i += 1

        return s    

    def interval(self, intervals):
        scale=self.chromatic()
        #print ('scale=',scale)
        r=[]
        r.append(scale[0])
        j=0
        for i in intervals:
            if i == "M":
                j += 2
            elif i == "m":
                j += 1
            else:
                j += 3
            #print("j:",j)
            if j <= 11:
                r.append(scale[j])
        return r

