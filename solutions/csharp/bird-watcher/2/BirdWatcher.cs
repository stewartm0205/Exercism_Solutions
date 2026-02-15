using System;

class BirdCount
{
    private int[] birdsPerDay;
    private bool init;

    public BirdCount(int[] birdsPerDay)
    {
        this.birdsPerDay = birdsPerDay;
    }

    public static int[] LastWeek() => new[] {0, 2, 5, 3, 7, 8, 4};

    public int Today() => birdsPerDay[6];

    public void IncrementTodaysCount()
    {
        birdsPerDay[6]++;
    }

    public bool HasDayWithoutBirds()
    {
        foreach(int dc in birdsPerDay) if (dc == 0) return true;
        return false;
    }

    public int CountForFirstDays(int numberOfDays)
    {
        int fdc = 0;
        for (int d = 0; d<numberOfDays; d++) fdc += birdsPerDay[d];
        return fdc;
    }

    public int BusyDays()
    {
        int nbd = 0;
        for (int d = 0; d<7; d++) if (birdsPerDay[d] >= 5) nbd++;
        return nbd;
    }
}

