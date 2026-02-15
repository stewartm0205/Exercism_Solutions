public class PangramChecker {
    String alphabet = "abcdefghijklmnopqrstuvwxyz";
    public boolean isPangram(String input) {

        for (int i = 0; i < 26; i++){
            String l = alphabet.substring(i,i+1);
            if (input.indexOf(l)<0 && input.indexOf(l.toUpperCase())<0) return(false);
        }
        return(true);
    }

    void PangramChecker () {};
}