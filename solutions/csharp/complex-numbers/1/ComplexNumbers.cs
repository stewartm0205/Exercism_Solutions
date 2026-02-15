using System;

public struct ComplexNumber
{
    private double r;
    private double i;
    public ComplexNumber(double real, double imaginary)
    {
        r = real;
        i = imaginary;
    }

    public double Real() => r;

    public double Imaginary() => i;

    public ComplexNumber Mul(ComplexNumber other)
    {
        ComplexNumber t = new ComplexNumber();
        t.r = r * other.r - i * other.i;
        t.i = i * other.r + r * other.i;
        return t;
    }


    public ComplexNumber Add(ComplexNumber other)
    {
        ComplexNumber t = new ComplexNumber();
        t.r = r + other.r;
        t.i = i + other.i;
        return t;
    }

    public ComplexNumber Sub(ComplexNumber other)
    {
        ComplexNumber t = new ComplexNumber();
        t.r = r - other.r;
        t.i = i - other.i;
        return t;
    }

    public ComplexNumber Div(ComplexNumber other)
    {
        ComplexNumber t = new ComplexNumber();
        t.r = (r * other.r + i * other.i)/(other.r * other.r + other.i * other.i);
        t.i = (i * other.r - r * other.i)/(other.r * other.r + other.i * other.i);
        return t;
    }

    public double Abs()
    {
        return Math.Sqrt(r*r + i *i);
    }

    public ComplexNumber Conjugate()
    {
        ComplexNumber t = new ComplexNumber();
        t.r = r;
        t.i = -1 * i;
        return t;
    }

    public ComplexNumber Exp()
    {
        ComplexNumber t = new ComplexNumber();
        t.r = Math.Exp(r) * Math.Cos(i);
        t.i = Math.Exp(r) * Math.Sin(i);
        return t;
    }
}