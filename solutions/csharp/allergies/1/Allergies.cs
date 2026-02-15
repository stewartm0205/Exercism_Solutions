using System;
using System.Collections.Generic;


[Flags]
public enum Allergen : short
{
    Eggs=1,
    Peanuts=2,
    Shellfish=4,
    Strawberries=8,
    Tomatoes=16,
    Chocolate=32,
    Pollen=64,
    Cats=128
};

public class Allergies
{
    Allergen mask;
    public Allergies(int mask)
    {
        this.mask=(Allergen) mask;
    }

    public bool IsAllergicTo(Allergen allergen)
    {
        return (allergen & mask) != 0? true : false;
    }

    public Allergen[] List()
    {
        List<Allergen> al = new List<Allergen>();

        for (int m=1; m<=128; m=m<<1) {
            if (((Allergen) m & mask)!=0) al.Add((Allergen) m);
        }
        return al.ToArray();
    }
}