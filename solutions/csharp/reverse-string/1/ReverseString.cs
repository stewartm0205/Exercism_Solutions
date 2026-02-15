using System;

public static class ReverseString
{
    public static string Reverse(string input)
    {
        string r = "";
        foreach (char c in input)
        {
            r = c + r;
        }
        return r;
    }
}