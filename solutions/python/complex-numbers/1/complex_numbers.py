import math
class ComplexNumber:
    def __init__(self, real, imaginary):
        self.real=real
        self.imaginary=imaginary
       
    def __eq__(self, other):
        if type(other) is not ComplexNumber:
            return self.real == other
        else:
            return self.real == other.real and self.imaginary == other.imaginary

    def __add__(self, other):
        self.real += other.real
        self.imaginary += other.imaginary
        return(self)
        

    def __mul__(self, other):
        cmpl=ComplexNumber(0,0)
        cmpl.real = self.real * other.real - self.imaginary * other.imaginary 
        cmpl.imaginary = self.imaginary * other.real + self.real * other.imaginary
        return(cmpl)

    def __sub__(self, other):
        self.real -= other.real
        self.imaginary -= other.imaginary
        return(self)

    def __truediv__(self, other
    ):
        cmpl=ComplexNumber(0,0)
        cmpl.real = (self.real * other.real + self.imaginary * other.imaginary) / \
                    (other.real * other.real + other.imaginary * other.imaginary) 
        cmpl.imaginary = (self.imaginary * other.real - self.real * other.imaginary) / \
                    (other.real * other.real + other.imaginary * other.imaginary)
        return(cmpl)

    def __abs__(self):
        self.real = math.sqrt(self.real * self.real + self.imaginary * self.imaginary)
        del self.imaginary
        return(self)

    def conjugate(self):
        self.imaginary = -self.imaginary
        return(self)

    def exp(self):
        self = ComplexNumber(math.exp(self.real), 0) * \
               ComplexNumber(math.cos(self.imaginary),math.sin(self.imaginary))       
        return(self)

    def __round__(self,ndigs):
        self.real=round(self.real,ndigs)
        if hasattr(self,'imaginary'):
            self.imaginary=round(self.imaginary,ndigs)
        return(self)
