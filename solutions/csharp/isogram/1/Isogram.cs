using System;
using System.Collections.Generic;

public static class Isogram
{
    public static bool IsIsogram(string word)
    {
        Dictionary<char, int> cc = new Dictionary<char, int>();
        word = word.ToLower();
        foreach (char ch in word) {
            if (ch != ' ' && ch != '-') {
                if (cc.ContainsKey(ch)) {
                    return false;
                } else {
                    cc[ch] = 1;
                }
            }
        }
        return true;
    }
}
