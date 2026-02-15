using System;
using System.Collections.Generic;

public static class ResistorColorDuo
{
    static Dictionary<string,int> cv = new Dictionary<string, int>() {{"black", 0},{"brown", 1}, {"red", 2}, {"orange", 3},
        {"yellow", 4}, {"green", 5}, {"blue", 6},
        {"violet", 7}, {"grey", 8}, {"white", 9}};
    public static int Value(string[] colors)
    {
        return 10 * cv[colors[0]] + cv[colors[1]];
    }
}
