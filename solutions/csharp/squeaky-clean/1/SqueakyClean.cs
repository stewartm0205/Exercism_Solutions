using System;
using System.Text.RegularExpressions;

public static class Identifier
{
    public static string Clean(string identifier)
    {
        string ret = identifier.Replace(" ","_");
        ret = Regex.Replace(ret,@"[\u0000-\u001f]+","CTRL");
        ret = Regex.Replace(ret,"-.",m=>m.Value.ToUpper().Substring(1));
        ret = Regex.Replace(ret,@"[0-9\W]+","");
        ret = Regex.Replace(ret,@"[\u03b1-\u03bf\u03c0-\u03c9]+","");
        return ret;
    }
}
