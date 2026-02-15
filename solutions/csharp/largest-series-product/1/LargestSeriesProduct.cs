using System;

public static class LargestSeriesProduct
{
    public static long GetLargestProduct(string digits, int span)
    {
        if (span > digits.Length) {
            throw new ArgumentException();
        }
        if (span > 0 && digits.Length == 0) {
            throw new ArgumentException();
        }
        if (span < 0) {
            throw new ArgumentException();
        }
        long lsp = 0;
        for (int i=0; i<=digits.Length-span; i++){
            long sp = 1;
            int n;
            for (int j=0; j<span; j++){
                if (int.TryParse(digits.Substring(i+j,1), out n)) {
                    sp*=n;
                } else {
                    throw new ArgumentException();
                }

            }
            if (sp > lsp) lsp = sp;
        }
        return lsp;
        //throw new NotImplementedException("You need to implement this function.");
    }
}