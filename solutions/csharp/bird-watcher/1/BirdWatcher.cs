using System;

class BirdCount
{
    private static int[] birdsPerDay;
    private bool init;

    public BirdCount()
    {
        BirdCount.birdsPerDay = new int[] {0, 2, 5, 3, 7, 8, 4};

    }
    public BirdCount(int[] birdsPerDay)
    {
        BirdCount.birdsPerDay = birdsPerDay;
    }

    public static int[] LastWeek()
    {
        return BirdCount.birdsPerDay;
    }

    public int Today()
    {
        return LastWeek()[6];
    }

    public void IncrementTodaysCount()
    {
        BirdCount.birdsPerDay[6]++;
    }

    public bool HasDayWithoutBirds()
    {
        foreach(int dc in BirdCount.birdsPerDay) if (dc == 0) return true;
        return false;
    }

    public int CountForFirstDays(int numberOfDays)
    {
        int fdc = 0;
        for (int d = 0; d<numberOfDays; d++) fdc += BirdCount.birdsPerDay[d];
        return fdc;
    }

    public int BusyDays()
    {
        int nbd = 0;
        for (int d = 0; d<7; d++) if (BirdCount.birdsPerDay[d] >= 5) nbd++;
        return nbd;
    }
}

