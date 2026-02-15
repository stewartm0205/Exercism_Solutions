#include "complex_numbers.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

complex_t c_add(complex_t a, complex_t b)
{
   complex_t t;
   t.real = a.real + b.real;
   t.imag = a.imag + b.imag;
   return t;
}

complex_t c_sub(complex_t a, complex_t b)
{
   complex_t t;
   t.real = a.real - b.real;
   t.imag = a.imag - b.imag;
   return t;
}

complex_t c_mul(complex_t a, complex_t b)
{
   complex_t t;
   t.real = a.real * b.real - a.imag * b.imag;
   t.imag = a.imag * b.real + a.real * b.imag;
   return t;
}

complex_t c_div(complex_t a, complex_t b)
{
   complex_t t;
   t.real = (a.real * b.real + a.imag * b.imag)/(b.real * b.real + b.imag * b.imag);
   t.imag = (a.imag * b.real - a.real * b.imag)/(b.real * b.real + b.imag * b.imag);
   return t;
}

double c_abs(complex_t x)
{
   return sqrt(x.real*x.real+x.imag*x.imag);
}

complex_t c_conjugate(complex_t x)
{
   complex_t t;
   t.real = x.real;
   t.imag = -1 * x.imag;
   return t;
}

double c_real(complex_t x)
{
   return x.real;
}

double c_imag(complex_t x)
{
   return x.imag;
}

complex_t c_exp(complex_t x)
{
   complex_t t;
   t.real = exp(x.real)*cos(x.imag);
   t.imag = exp(x.real)*sin(x.imag);
   return t;
}
