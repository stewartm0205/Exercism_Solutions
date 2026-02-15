using System;
using System.Collections.Generic;

public static class PythagoreanTriplet
{
    public static IEnumerable<(int a, int b, int c)> TripletsWithSum(int sum)
    {
        IEnumerable<(int a, int b, int c)> pt = new List<(int a, int b, int c)>();
        for (int a=1; a<=sum-3; a++) {
            for (int b=a+1; b<sum-2; b++) {
                int c = sum - (a+b);
                if (a*a + b*b == c*c) {
                    yield return (a, b, c);
                }
            }
        }
        //throw new NotImplementedException("You need to implement this function.");
    }
}