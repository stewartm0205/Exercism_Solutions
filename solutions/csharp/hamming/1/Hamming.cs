using System;

public static class Hamming
{
    public static int Distance(string firstStrand, string secondStrand)
    {
        int d = 0;
        if (firstStrand.Length != secondStrand.Length) { throw new System.ArgumentException();}
        for (int i=0; i < firstStrand.Length; i++)
        {
            if (!firstStrand.Substring(i,1).Equals(secondStrand.Substring(i,1))) { d++; }
        }
        return d;
    }
}