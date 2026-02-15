using System;

public static class ScrabbleScore
{
    public static int Score(string input)
    {
        int score = 0;
        input = input.ToUpper();
        foreach (char ch in input) {
            if ("A, E, I, O, U, L, N, R, S, T".Contains(ch)) score += 1;
            if ("D, G".Contains(ch)) score += 2;
            if ("B, C, M, P".Contains(ch)) score += 3;
            if ("F, H, V, W, Y".Contains(ch)) score += 4;
            if (ch=='K') score += 5;
            if ("J, X".Contains(ch)) score += 8;
            if ("Q, Z".Contains(ch)) score += 10;
        }
        return score;
    }
}