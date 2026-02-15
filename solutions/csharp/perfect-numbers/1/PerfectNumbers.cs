using System;

public enum Classification
{
    Perfect,
    Abundant,
    Deficient
}

public static class PerfectNumbers
{
    public static Classification Classify(int number)
    {
        if (number <= 0) throw new ArgumentOutOfRangeException();
        if (number == 1) return Classification.Deficient;
        int fs = 1;
        for (int n = 2; n<number; n++) {
            if (number % n == 0) fs += n;
        }
        if (fs==number) return Classification.Perfect;
        if (fs > number) return Classification.Abundant;
        return Classification.Deficient;
    }
}
