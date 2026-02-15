using System;
using System.Collections.Generic;

public class Robot
{
    private string name;
    static List<string> names = new List<string>();

    public Robot () {
        Random rnd = new Random();
        char char1 = (char)('A' + rnd.Next(26));
        char char2 = (char)('A' + rnd.Next(26));
        name = String.Format("{0}{1}{2:D3}", char1.ToString(), char2.ToString(), rnd.Next(999));
        while (names.IndexOf(name)>=0) {
            name = String.Format("{0}{1}{2:D3}", char1.ToString(), char2.ToString(), rnd.Next(999));
        }
        names.Add(name);
    }


    public string Name
    {
        get => name;

    }

    public void Reset()
    {
        Random rnd = new Random();
        char char1 = (char)('A' + rnd.Next(26));
        char char2 = (char)('A' + rnd.Next(26));
        name = String.Format("{0}{1}{2:D3}", char1.ToString(), char2.ToString(), rnd.Next(999));
        while (names.IndexOf(name)>=0) {
            name = String.Format("{0}{1}{2:D3}", char1.ToString(), char2.ToString(), rnd.Next(999));
        }
        names.Add(name);
    }

}