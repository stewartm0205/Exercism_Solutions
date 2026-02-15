using System;

static class SavingsAccount
{
    public static float InterestRate(decimal balance)
    {
        if (balance < 0) return (float) 3.213;
        if (balance < 1000) return (float)0.5;
        if (balance < 5000) return (float)1.621;
        return (float)2.475;
    }

    public static decimal Interest(decimal balance)
    {
        return balance * (decimal) InterestRate (balance) / 100m;
    }

    public static decimal AnnualBalanceUpdate(decimal balance)
    {
        return balance + Interest(balance);
    }

    public static int YearsBeforeDesiredBalance(decimal balance, decimal targetBalance)
    {
        int y = 0;
 while (balance < targetBalance)
        {
            y++;
            balance = AnnualBalanceUpdate(balance);
        }
        return y;

    }
}
