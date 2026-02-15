using System;
using System.Collections.Generic;

public enum SublistType
{
    Equal,
    Unequal,
    Superlist,
    Sublist
}

public static class Sublist
{
    public static SublistType Classify<T>(List<T> list1, List<T> list2)
        where T : IComparable
    {
        if (list1.Count == list2.Count)
        {
            for (int i =0; i< list1.Count; i++) {
                if (!list1[i].Equals(list2[i])) return SublistType.Unequal;
            }
            return SublistType.Equal;
        } else if (list1.Count < list2.Count)
        {
            if (list1.Count == 0) return SublistType.Sublist;
            for (int j =0; j<= list2.Count-list1.Count; j++)
            {
                if (list1[0].Equals(list2[j]))
                {
                    int i;
                    for (i=1; i< list1.Count; i++)
                    {
                        if (!list1[i].Equals(list2[j+i])) break;
                    }
                    if (i==list1.Count) return SublistType.Sublist;
                }
            }
            return SublistType.Unequal;
        } else
        {
            if (list2.Count == 0) return SublistType.Superlist;
            for (int j =0; j<= list1.Count-list2.Count; j++)
            {
                if (list1[j].Equals(list2[0]))
                {
                    int i;
                    for (i=1; i< list2.Count; i++) {
                        if (!list1[j+i].Equals(list2[i])) break;
                    }
                    if (i==list2.Count) return SublistType.Superlist;
                }
            }
            return SublistType.Unequal;
        }
    }
}