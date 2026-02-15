import java.util.HashMap;
import java.util.Map;

public class WordCount {

    Map<String, Integer> wordCount;
    String punct = "!!&@$%^&";
    WordCount() {
        wordCount = new HashMap();
    }

    Map<String, Integer> phrase (String sentence) {
        sentence = sentence.replaceAll("( )+", " ");
        sentence = sentence.replaceAll("(!|&|@|\\$|%|\\^|&|\\.)+", "");
        sentence = sentence.trim();
        sentence = sentence.toLowerCase();
        System.out.println("sentence="+sentence);
        for (String word : sentence.split("(\n| |,|:)+", 0)) {
            System.out.println("word="+word);
            System.out.println(word.substring(0,1)+word.substring(word.length()-1,word.length()));
            if (word.substring(0,1).equals("'") && word.substring(word.length()-1,word.length()).equals("'")){
                word = word.substring(1,word.length()-1);
                //System.out.println("word="+word);
            }
            if (wordCount.get(word) == null) {
                wordCount.put(word, 1);
            } else {
                wordCount.put(word, wordCount.get(word)+1);
            }
        }

        return(wordCount);
    }
}