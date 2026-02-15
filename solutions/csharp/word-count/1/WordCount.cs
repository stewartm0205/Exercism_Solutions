using System;
using System.Collections.Generic;
using System.Text.RegularExpressions;

public static class WordCount
{
    public static IDictionary<string, int> CountWords(string phrase)
    {
        phrase = phrase.ToLower();
        phrase = Regex.Replace(phrase,"[^a-z0-9 ']+", " ");
        phrase = phrase.Trim();
        phrase =phrase.Replace("  "," ");
        phrase =phrase.Replace("  "," ");

        string[] words = phrase.Split(new char[0]);
        IDictionary<string, int> wc = new Dictionary<string, int>();
        char[] apos = {'\'','"'};
        foreach(string word in words) {
           string tword = word.Trim(apos);
           if(wc.ContainsKey(tword)) wc[tword]++;
           else wc.Add(tword.ToLower(),1);
        }
        return wc;
        //throw new NotImplementedException("You need to implement this function.");
    }
}