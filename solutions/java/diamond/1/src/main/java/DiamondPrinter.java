import java.util.List;
import java.util.ArrayList;

class DiamondPrinter {
    String alphabet = "abcdefghijklmnopqrstuvwxyz".toUpperCase();

    List<String> printToList(char a) {
        int l = alphabet.indexOf(a);
        int ns = 2*l-1;
        System.out.println("l="+l);
        System.out.println("ns="+ns);
        List<String> diamond = new ArrayList<String>();
        String spaces = "                                                     ";
        //String spaces = "............................";
        String dl;
        for (int i = 0; i <= l; i++) {
            if (i==0) {
                dl = spaces.substring(0,l-i) + alphabet.substring(i, i+1) + spaces.substring(0,l-i);
            } else {
                dl = spaces.substring(0,l-i) + alphabet.substring(i, i+1) + spaces.substring(0,ns - 2 * (l - i)) +
                        alphabet.substring(i, i+1) + spaces.substring(0,l-i);
            }
            System.out.println("dl=|"+dl+"|");
            diamond.add(dl);
        }
        for (int i = l-1; i >= 0; i--) {
            if (i==0) {
                dl = spaces.substring(0, l - i) + alphabet.substring(i, i + 1) + spaces.substring(0, l - i);
            } else {
                dl = spaces.substring(0,l-i) + alphabet.substring(i, i+1) + spaces.substring(0,ns - 2 * (l - i)) +
                        alphabet.substring(i, i+1) + spaces.substring(0,l-i);
            }
            System.out.println("dl=|"+dl+"|");
            diamond.add(dl);
        }
        return(diamond);
    }

}