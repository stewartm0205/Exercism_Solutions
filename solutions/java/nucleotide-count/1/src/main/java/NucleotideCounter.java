import java.util.Map;
import java.util.HashMap;

public class NucleotideCounter {
    String DNA;
    Map<Character, Integer> counts;

    NucleotideCounter (String DNA){
        this.DNA = DNA;
        counts = new HashMap<Character, Integer>();
        counts.put('A',0);
        counts.put('C',0);
        counts.put('G',0);
        counts.put('T',0);

        for (int i = 0; i < DNA.length(); i++) {
            if ("ACGT".indexOf(DNA.substring(i,i+1))<0) {
                throw new IllegalArgumentException();
            } else {
                counts.put(DNA.charAt(i), counts.get(DNA.charAt(i)) + 1);
            }
        }
    }

    Map<Character, Integer> nucleotideCounts() {
        return(counts);
    }
}