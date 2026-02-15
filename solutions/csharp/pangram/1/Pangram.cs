using System;

public static class Pangram
{
    public static bool IsPangram(string input)
    {
        int[] charcount = new int[26];
        input = input.ToLower();
        foreach  (char ch in input) {
            if (ch>='a' && ch <='z') {
                charcount[ch-'a']++;
           }
        }

        for (int i = 0; i<26; i++) {
            if (charcount[i] == 0) return false;
        }
        return true;
    }
}
