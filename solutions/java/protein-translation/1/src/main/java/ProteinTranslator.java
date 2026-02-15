import java.util.List;
import java.util.ArrayList;

class ProteinTranslator {
    String codons[] = {"AUG", "UUU", "UUC","UUA","UUG", "UCU","UCC", "UCA","UCG",
                        "UAU", "UAC", "UGU", "UGC", "UGG", "UAA", "UAG", "UGA"};

    String proteins[] = {"Methionine", "Phenylalanine","Phenylalanine",
                         "Leucine","Leucine", "Serine","Serine","Serine","Serine",
                        "Tyrosine","Tyrosine", "Cysteine", "Cysteine", "Tryptophan",
                        "STOP","STOP","STOP"};

    List<String> translate(String rnaSequence) {
        String codon = "";
        List<String> protein = new ArrayList<String>();
        boolean cont = true;

        for (int ci = 0; cont & (ci < rnaSequence.length() / 3); ci++){
            codon = rnaSequence.substring(ci*3, ci*3 + 3);
            //System.out.println("codon="+codon);
            for (int si = 0; cont & si < codons.length; si++){
                if (codons[si].equals(codon)) {
                    //System.out.println("protein="+proteins[si]);
                    if (proteins[si].equals("STOP"))
                        cont = false;
                    else
                        protein.add(proteins[si]);
                }
            }
        }
        return(protein);
    }

    ProteinTranslator () {

    }
}