public class PigLatinTranslator {

    String translate (String englishPhrase) {
        String vowels = "aeiou";
        String pigLatinPhrase = "";
        String pigLatinWord = "";
        int wi = 0;
        for (String word : englishPhrase.split(" ", 0)) {
            wi++;
            //System.out.println("word="+word);
            //System.out.println("word(0,1)="+word.substring(0,1));
           // System.out.println("word(0,2)="+word.substring(0,2));
            //System.out.println("word(0,3)="+word.substring(0,3));
           if (word.substring(0,3).equals("squ") || word.substring(0,3).equals("thr") || word.substring(0,3).equals("sch")) {
               pigLatinWord = word.substring(3,word.length()) + word.substring(0, 3) + "ay";
               // System.out.println("3 chars");
           }
            else if (word.substring(0,2).equals("ch") || word.substring(0,2).equals("qu") || word.substring(0,2).equals("th")) {
               pigLatinWord = word.substring(2,word.length()) + word.substring(0, 2) + "ay";
              // System.out.println("2 chars");
           }
            else if (word.substring(0,2).equals("xr") ||
                   word.substring(0,2).equals("yt")) {
               pigLatinWord = word + "ay";
               //System.out.println("2 chars vowel");
           }
            else if (vowels.indexOf(word.substring(0,1)) >= 0) {
               pigLatinWord = word + "ay";
               //System.out.println("1 char vowel");
           }
            else {
               pigLatinWord = word.substring(1, word.length()) + word.substring(0, 1) + "ay";
               //System.out.println("1 char");
           }
           if (wi > 1) pigLatinPhrase += " " + pigLatinWord;
           else pigLatinPhrase = pigLatinWord;
        }
        return (pigLatinPhrase);
    }
}