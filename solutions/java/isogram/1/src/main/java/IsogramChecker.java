class IsogramChecker {

    boolean isIsogram(String phrase) {
        String lcphrase = phrase.toLowerCase();
        String alphabet="abcdefghijklmnopqrstuvwxyz";
        int[] lc = new int[26];
        boolean isogram = true;
        for (int i = 0; i < 26; i++) lc[i]=0;
        for (int i = 0; i < lcphrase.length(); i++){
            int j = alphabet.indexOf(lcphrase.substring(i,i+1));
            if (j>=0) lc[j]++;
        }
        for (int i = 0; i < 26; i++) if (lc[i]>1) isogram = false;
        return(isogram);
    }

}