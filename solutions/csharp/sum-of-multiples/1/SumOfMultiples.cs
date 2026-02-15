using System;
using System.Collections.Generic;

public static class SumOfMultiples
{
    public static int Sum(IEnumerable<int> multiples, int max)
    {
        int s=0;
        for (int n=1; n<max; n++) {
            foreach (int d in multiples) {
                if (d !=0 && n % d == 0) {
                    s+=n;
                    break;
                }
            }

        }
        return s;
        //throw new NotImplementedException("You need to implement this function.");
    }
}