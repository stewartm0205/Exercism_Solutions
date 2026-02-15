using System;

public static class RnaTranscription
{
    public static string ToRna(string nucleotide)
    {
        string rna = "";
        foreach (char n in nucleotide)
        {
            rna = rna + "CGAU".Substring("GCTA".IndexOf(n), 1);
        }
        return rna;
    }
}