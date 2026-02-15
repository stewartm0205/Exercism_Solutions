using System;
using System.Collections.Generic;

public static class PrimeFactors
{
    public static long[] Factors(long number)
    {
        List<long> pf = new List<long>();
        if (number == 1L) return pf.ToArray();
        for (int i = 2; i<=number; i++) {
            if (number % i == 0) {
                int j;
                for (j = 0; j<pf.Count; j++) {
                    if (i % pf[j] == 0) break;
                }
                if (j == pf.Count) {
                    pf.Add(i);
                    number = number / i;
                    while (number % i == 0){
                        pf.Add(i);
                        number = number / i;
                    }
                }

            }
        }
        return pf.ToArray();
        //throw new NotImplementedException();
    }
}