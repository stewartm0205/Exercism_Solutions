using System;

public static class DifferenceOfSquares
{
    public static int CalculateSquareOfSum(int max)
    {
        int ss = 0;
        for (int n = 1; n<= max; n++) ss += n;
        return ss*ss;
    }

    public static int CalculateSumOfSquares(int max)
    {
        int ss = 0;
        for (int n = 1; n<= max; n++) ss += n * n;
        return ss;
    }

    public static int CalculateDifferenceOfSquares(int max)
    {
        return CalculateSquareOfSum(max) - CalculateSumOfSquares(max);
    }
}