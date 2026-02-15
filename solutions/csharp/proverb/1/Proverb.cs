using System;
using System.Collections.Generic;

public static class Proverb
{
    public static string[] Recite(string[] subjects)
    {
        List<string> pb = new List<string>();

        for (int si = 0; si<subjects.Length-1; si++)  {

            pb.Add($"For want of a {subjects[si]} the {subjects[si+1]} was lost.");

        }
        if (subjects.Length>0) pb.Add($"And all for the want of a {subjects[0]}.");
        return pb.ToArray();
    }
}