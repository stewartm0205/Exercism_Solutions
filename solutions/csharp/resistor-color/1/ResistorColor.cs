using System;
using System.Collections.Generic;

public static class ResistorColor
{
    static Dictionary<string,int> colors = new Dictionary<string, int>() {{"black", 0},{"brown", 1}, {"red", 2}, {"orange", 3},
        {"yellow", 4}, {"green", 5}, {"blue", 6},
        {"violet", 7}, {"grey", 8}, {"white", 9}};
    public static int ColorCode(string color)
    {
        return colors[color];
    }

    public static string[] Colors()
    {
        string[] rcolor = new string[10];
        int i=0;
        foreach (var item in colors){
            rcolor[i++] = item.Key;
        }
        return rcolor;
    }
}