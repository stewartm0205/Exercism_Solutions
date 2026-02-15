using System;

public static class BeerSong
{
    public static string Recite(int startBottles, int takeDown)
    {
        string song ="";
        for (int bb = startBottles; bb > startBottles - takeDown; bb--) {
            if (bb>0)
            {

                if (bb == 1)
                {
                    song += $"1 bottle of beer on the wall, 1 bottle of beer.\n";
                    song += "Take it down and pass it around, no more bottles of beer on the wall.";
                } else if (bb == 2)
                {
                    song += $"{bb} bottles of beer on the wall, {bb} bottles of beer.\n";
                    song += $"Take one down and pass it around, 1 bottle of beer on the wall.";
                } else
                {
                    song += $"{bb} bottles of beer on the wall, {bb} bottles of beer.\n";
                    song += $"Take one down and pass it around, {bb-1} bottles of beer on the wall.";
                }
            } else {
                song += "No more bottles of beer on the wall, no more bottles of beer.\n" +
                 "Go to the store and buy some more, 99 bottles of beer on the wall.";
            }
            song += "\n\n";
        }
        return song.Substring(0,song.Length-2);
    }
}