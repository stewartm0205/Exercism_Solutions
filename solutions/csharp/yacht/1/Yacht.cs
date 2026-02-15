using System;

public enum YachtCategory
{
    Ones = 1,
    Twos = 2,
    Threes = 3,
    Fours = 4,
    Fives = 5,
    Sixes = 6,
    FullHouse = 7,
    FourOfAKind = 8,
    LittleStraight = 9,
    BigStraight = 10,
    Choice = 11,
    Yacht = 12,
}

public static class YachtGame
{
    public static int Score(int[] dice, YachtCategory category)
    {
        int s=0;
        int[] c = new int[7];
        if ((int)category>= 1 && (int)category<=6){
            for (int i = 0; i<5; i++) if (dice[i] == (int) category) s+= (int)category;
            return s;
        }
        for (int i=0;i<5;i++) {
            c[dice[i]]++;
        }
        int five_of_kind = 0;
        int four_of_kind = 0;
        int three_of_kind = 0;
        int two_of_kind = 0;

        for (int i=0;i<5;i++) {
            if (c[dice[i]] == 2) two_of_kind = i;
            if (c[dice[i]] == 3) {
                if (two_of_kind == i) two_of_kind = 0;
                three_of_kind = i;
            }
            if (c[dice[i]] == 4) {
                if (three_of_kind == i) three_of_kind = 0;
                four_of_kind = i;
            }
            if (c[dice[i]] == 5) {
                if (four_of_kind == i) four_of_kind = 0;
                five_of_kind = i;
            }
        }

        if (category == YachtCategory.FullHouse) {
            if (three_of_kind > 0 && two_of_kind>0) return 3*dice[three_of_kind]+2*dice[two_of_kind];
            return 0;
        }
        if (category == YachtCategory.FourOfAKind) {
            if (four_of_kind > 0 || five_of_kind> 0) return 4*dice[four_of_kind];
            return 0;
        }
        if (category == YachtCategory.Yacht) {
            if (five_of_kind > 0) return 50;
            return 0;
        }

        if (category == YachtCategory.LittleStraight) {
            bool little_straight = true;
            if (c[1] != 1) little_straight = false;
            for (int i=2;i<6;i++) {
                if (c[i]!=1) little_straight = false;
            }
            if (little_straight) return 30;
            return 0;
        }
        if (category == YachtCategory.BigStraight) {
            bool big_straight = true;
            if (c[1] != 0) big_straight = false;
            for (int i=2;i<7;i++) {
                if (c[i]!=1) big_straight = false;
            }
            if (big_straight) return 30;
            return 0;
        }
        if (category == YachtCategory.Choice) {
            for (int i=0;i<5;i++) {
                s+=dice[i];
            }
            return s;
        }
        return 0;

    }
}

