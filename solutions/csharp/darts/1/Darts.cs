using System;

public static class Darts
{
    public static int Score(double x, double y)
    {
        if (Math.Sqrt(x*x+y*y) > 10) return 0;
        if (Math.Sqrt(x*x+y*y) > 5) return 1;
        if (Math.Sqrt(x*x+y*y) > 1) return 5;
        return 10;
    }
}
