using System;
using System.Text.RegularExpressions;

public static class Luhn
{
    public static bool IsValid(string number)
    {

        int s=0;
        number = number.Replace(" ","");
        if (number.Length<=1) return false;
        if (Regex.IsMatch(number,@"[^0-9]+")) return false;
        bool even=false;
        int d;
        for (int i=number.Length-1;i>=0;i--){
            d=Int32.Parse(number.Substring(i,1));
            if (even) {
                d = 2 * d;
                if (d > 9) d-=9;
                even=false;
            } else even = true;
            s += d;
        }
        if (s % 10 == 0) return true;
        else return false;
    }
}