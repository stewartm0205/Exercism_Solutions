class TwelveDays {
    String[] days = {"first","second","third","fourth", "fifth","sixth",
                   "seventh", "eighth", "ninth", "tenth", "eleventh", "twelfth"};
    String[] presents = {"a Partridge in a Pear Tree","two Turtle Doves", "three French Hens","four Calling Birds",
                         "five Gold Rings","six Geese-a-Laying","seven Swans-a-Swimming","eight Maids-a-Milking",
                         "nine Ladies Dancing","ten Lords-a-Leaping","eleven Pipers Piping","twelve Drummers Drumming"};

       String verse(int verseNumber) {
        String verse = "On the " + days [verseNumber - 1] + " day of Christmas my true love gave to me, ";
        for(int i = verseNumber - 1; i > 0; i--){
            //System.out.println("i="+i);
            verse += presents[i]+ ", ";
        }
        if (verseNumber > 1)verse += "and ";
        verse += presents[0]+".\n";
        //System.out.println("verse="+verse);
        return(verse);
    }

    String verses(int startVerse, int endVerse) {
           String verse ="";
        for(int vi = startVerse; vi < endVerse; vi++) verse += verse(vi) + "\n";
        verse += verse(endVerse);
        return(verse);
    }
    
    String sing() {
        return(verses(1,12));
    }
}