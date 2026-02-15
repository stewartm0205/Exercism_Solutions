using System;
using System.Text.RegularExpressions;

public static class MatchingBrackets
{
    public static bool IsPaired(string input)
    {

        Regex nobr = new Regex("[^\\[\\]{}()]+");
        string ret=input;
        var matches = nobr.Matches(ret);
        while (matches.Count > 0)
        {
            ret = Regex.Replace(ret,"[^\\[\\]{}()]+", "");
            matches = nobr.Matches(ret);
        }
        Regex blbr = new Regex("\\(\\)|{}|\\[\\]");
        matches = blbr.Matches(ret);
        while (matches.Count > 0)
        {
            ret = Regex.Replace(ret, "\\(\\)|{}|\\[\\]", "");
            matches = blbr.Matches(ret);
        }
        if (ret.Length>0) return false;
        return true;
    }


}
