using System;
using System.Collections.Generic;

public static class ProteinTranslation
{
    public static string[] Proteins(string strand)
    {
        List<string> prot = new List<string> ();
        for (int i=0;i<strand.Length;i+=3){
            switch (strand.Substring(i,3)){
                case "AUG": prot.Add("Methionine"); break;
                case "UUU": case "UUC" : prot.Add(  "Phenylalanine"); break;
                case "UUA": case "UUG": prot.Add( 	"Leucine"); break;
                case "UCU": case "UCC": case "UCA": case "UCG":	prot.Add("Serine"); break;
                case "UAU": case "UAC": prot.Add(  	"Tyrosine"); break;
                case "UGU": case "UGC": prot.Add( "Cysteine"); break;
                case "UGG": prot.Add("Tryptophan"); break;
                case "UAA": case "UAG": case "UGA":	return prot.ToArray();
            }
        }
        return prot.ToArray();
    }
}