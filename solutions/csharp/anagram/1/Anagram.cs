using System;
using System.Collections.Generic;



public class Anagram
{
    string sortedBaseWord;
    string baseWord;
    public Anagram(string baseWord)
    {
        //throw new NotImplementedException("You need to implement this function.");
        this.baseWord = baseWord;
        char[] bwChars = baseWord.ToLower().ToCharArray();
        Array.Sort(bwChars);
        this.sortedBaseWord= new string(bwChars);

    }

    public string[] FindAnagrams(string[] potentialMatches)
    {
        List<string> matches = new List<string>();
        foreach(var pm in potentialMatches) {
            char[] pmChars = pm.ToLower().ToCharArray();
            Array.Sort(pmChars);
            var sortedPM = new string(pmChars);
            if (sortedPM == this.sortedBaseWord &&
                pm.ToLower() != this.baseWord.ToLower()) {
                matches.Add(pm);
            }
        }

        return matches.ToArray();
        //throw new NotImplementedException("You need to implement this function.");
    }
}