class Proverb {

        String[] words = new String[10];

        String[] lines  = { "For want of a nail the shoe was lost.\n",
                            "For want of a shoe the horse was lost.\n",
                            "For want of a horse the rider was lost.\n",
                            "For want of a rider the message was lost.\n",
                            "For want of a message the battle was lost.\n",
                            "For want of a battle the kingdom was lost.\n",
                            "And all for the want of a nail.",
                            "For want of a pin the gun was lost.\n",
                            "For want of a gun the soldier was lost.\n",
                            "For want of a soldier the battle was lost.\n",
                            "And all for the want of a pin."};


    Proverb(String[] words) {
        for (int wi = 0; wi < words.length; wi++) {
            //System.out.println(words[wi]);
            this.words[wi] = words[wi];
        }
    }

    String recite() {
        String proverb = "";
        for (int li = 0; li < lines.length; li++) {
            //System.out.println(lines[li]);
            for (int wi = 0; wi < words.length - 1; wi++) {
                //System.out.println(words[wi]);
                //System.out.println("want of a " + words[wi] + " the " + words[wi+1] + " was lost.");
                if (lines[li].indexOf("want of a " + words[wi] + " the " + words[wi+1] + " was lost.") >= 0) {
                    proverb += lines[li];
                }
            }
            //System.out.println(" "+words[0]+".");
            if (lines[li].indexOf(" "+words[0]+".")>=0) {
                proverb += lines[li];
            }

        }
       return (proverb);
    }

}