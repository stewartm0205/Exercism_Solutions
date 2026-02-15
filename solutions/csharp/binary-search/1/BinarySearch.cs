using System;

public static class BinarySearch
{
    public static int Find(int[] input, int value)
    {
        if (input.Length == 0) return -1;
        int sp = 0;
        int ep = input.Length-1;
        int mp = input.Length / 2;
        while (input[mp] != value)
        {
            if (sp == mp || mp == ep) return -1;
            if (input[sp] < value && input[sp+1]> value) return -1;
            if (value == input[sp]) return sp;
            if (value == input[ep]) return ep;
            if (value < input[mp]) ep = mp;
            else sp = mp;
            mp = (sp + ep) / 2;
        }
        return mp;
    }
}