using System;

public static class Grains
{
    public static ulong Square(int n)
    {
        if (n <= 0 || n>=65) throw new ArgumentOutOfRangeException();
        ulong s = 1;
        for (int i = 1; i<n; i++) {
            s *= 2;
        }
        return s;
    }

    public static ulong Total()
    {
        ulong t = 0;
        for (int i=1; i<=64; i++) {
            t+=Square(i);
        }
        return t;
    }
}