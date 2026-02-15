class Scrabble {
    String word;
    String letters[]={"AEIOULNRST","DG","BCMP", "FHVWY", "K", "JX", "QZ"};
    int score[] = {1, 2, 3, 4, 5, 8, 10};

    Scrabble(String word) {
        this.word = word;
    }

    int getScore() {
        int s = 0;
        //System.out.println("word="+word);
        for (int i = 0; i<word.length(); i++) {
            String l = word.substring(i, i+1).toUpperCase();
            //System.out.println("l="+l);
            for (int j = 0; j<7; j++) {
                if (letters[j].indexOf(l) >= 0) {
                    //System.out.println("j="+j);
                    s += score[j];
                    //System.out.println("s="+s);
                    break;
                }
            }
        }
        return(s);
    }

}