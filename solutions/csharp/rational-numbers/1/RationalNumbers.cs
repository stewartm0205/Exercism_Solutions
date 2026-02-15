using System;
using System.Diagnostics;

public static class RealNumberExtension
{
    public static double Expreal(this int realNumber, RationalNumber r)
    {
        return Math.Pow(Math.Pow(realNumber, r.Numerator()),1/r.Denominator());
    }
}

public struct RationalNumber
{
    double n;
    double d;
    public RationalNumber(int numerator, int denominator)
    {
        n = numerator;
        d = denominator;
        //double g = gcd(n,d);
        //n = n/g;
        //d = n/g;
    }

    public double Numerator() => n;
    public double Denominator() => d;
    public static RationalNumber operator +(RationalNumber r1, RationalNumber r2)
    {
        RationalNumber t = new RationalNumber();
        t.n = (r1.n * r2.d + r2.n * r1.d);
        t.d = r1.d * r2.d;
        return t.Reduce();
    }

    public static RationalNumber operator -(RationalNumber r1, RationalNumber r2)
    {
        RationalNumber t = new RationalNumber();
        t.n = (r1.n * r2.d - r2.n * r1.d);
        t.d = r1.d * r2.d;
        return t.Reduce();
    }

    public static RationalNumber operator *(RationalNumber r1, RationalNumber r2)
    {
        RationalNumber t = new RationalNumber();
        t.n = r1.n * r2.n;
        t.d = r1.d * r2.d;
        return t.Reduce();
    }

    public static RationalNumber operator /(RationalNumber r1, RationalNumber r2)
    {
        RationalNumber t = new RationalNumber();
        t.n = r1.n * r2.d;
        t.d = r1.d * r2.n;
        return t.Reduce();
    }

    public RationalNumber Abs()
    {
        RationalNumber t = new RationalNumber();
        if (n < 0 && d <0)
        {
            t.n = -n;
            t.d = -d;
        }
        else if (n < 0 && d>0)
        {
            t.n = -n;
            t.d = d;
        }
        else if (n >0 && d <0)
        {
            t.n = n;
            t.d = -d;
        } else
        {
            t.n = n;
            t.d = d;
        }
        return t.Reduce();
    }

    public RationalNumber Reduce()
    {
        RationalNumber t = new RationalNumber();
        double g = gcd(n,d);
        t.n = n/g;
        t.d = d/g;
        if (t.d < 0) {
            t.n = -1 * t.n;
            t.d = -1 * t.d;
        }
        if (t.n == 0) t.d = 1;
        return t;
    }

    public RationalNumber Exprational(int power)
    {
        RationalNumber t = new RationalNumber();
        t.n = Math.Pow(n, power);
        t.d = Math.Pow(d, power);
        return t.Reduce();
    }

    public double Expreal(int baseNumber)
    {
        return Math.Pow(Math.Pow(baseNumber,n),1/d);
    }

    public double gcd(double n1, double n2) {
        if (n2 == 0) return n1;
        else return gcd(n2, n1 % n2);
    }
}