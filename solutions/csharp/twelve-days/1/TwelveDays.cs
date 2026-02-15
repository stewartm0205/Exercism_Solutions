using System;

public static class TwelveDays
{
    public static string Recite(int verseNumber)
    {
        string[] days = {"first","second","third","fourth","fifth","sixth","seventh","eighth","ninth","tenth","eleventh","twelfth"};
        string[] gifts = {"a Partridge in a Pear Tree.","two Turtle Doves,","three French Hens,",
"four Calling Birds,","five Gold Rings,", "six Geese-a-Laying,","seven Swans-a-Swimming,", "eight Maids-a-Milking,", "nine Ladies Dancing,","ten Lords-a-Leaping,", "eleven Pipers Piping,","twelve Drummers Drumming,"};
        string verse = $"On the {days[verseNumber-1]} day of Christmas my true love gave to me:";
        string giftsPhrase = "";
        for (int d = verseNumber - 1 ; d >= 0; d--){
            if (d == 0 && giftsPhrase != "") giftsPhrase += " and";
            giftsPhrase = giftsPhrase + " " + gifts[d];
        }
        verse += giftsPhrase;
        return verse;

        //throw new NotImplementedException("You need to implement this function.");
    }

    public static string Recite(int startVerse, int endVerse)
    {
        string verses = "";
        for (int vn = startVerse; vn <= endVerse; vn++)
        {
            verses += Recite(vn) +'\n';
        }
        return verses.Trim();
        //throw new NotImplementedException("You need to implement this function.");
    }
}