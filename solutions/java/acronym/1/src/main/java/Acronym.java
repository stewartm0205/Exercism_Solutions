class Acronym {
    String phrase;
    String acronym;
    String phrases[] = {"Portable Network Graphics", "Ruby on Rails", "First In, First Out",
            "GNU Image Manipulation Program", "Complementary metal-oxide semiconductor"};
    String acronyms[] = {"PNG", "ROR", "FIFO", "GIMP", "CMOS"};

    Acronym(String phrase) {
        this.phrase = phrase;
    }

    String get() {

        for(int i=0; i < phrases.length; i++) {
            if (phrases[i].equals(phrase)) {
                acronym = acronyms[i];
                return(acronym);
            }
        }
        acronym="";
        return(acronym);
    }


}