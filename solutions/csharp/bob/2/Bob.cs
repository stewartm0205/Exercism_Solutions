using System;
using System.Text.RegularExpressions;

public static class Bob
{
    public static string Response(string statement)
    {

        var pattern = @"^.*\? *$"; // Question
        Match m = Regex.Match(statement, pattern);

        if (m.Success)
        {
            pattern = @"^.*[a-zA-Z]+.*$"; // Question
            m = Regex.Match(statement, pattern);
            if (m.Success && statement.ToUpper() == statement) return "Calm down, I know what I'm doing!";
            else return "Sure.";
        }

        pattern = @"^[\t\r\n ]*$";
        m = Regex.Match(statement, pattern);

        if (m.Success) return "Fine. Be that way!";

        pattern = @"^.*[a-zA-Z]+.*$"; // Question
        m = Regex.Match(statement, pattern);

        if (m.Success && statement.ToUpper() == statement) return "Whoa, chill out!";

        return "Whatever.";
    }
}