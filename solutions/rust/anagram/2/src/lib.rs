use std::collections::HashSet;

pub fn anagrams_for<'a>(word: &str, possible_anagrams: &[&str]) -> HashSet<&'a str> {
   //convert to all lowercase and sort the word
   // for each word in possible convert to lowercase and sort and compare to word
    let mut anags = HashSet::<&'a str>::new();
    let mut lword: String = word.to_lowercase();
    let mut slchars: Vec<char> = lword.chars().collect();
    slchars.sort();
    let slword: String = slchars.iter().collect();
    let lpword: String;
    let mut slpchars: Vec<char>;
    let slpword:String;
    for pword in possible_anagrams {
        lpword = pword.to_lowercase();
        slpchars = lpword.chars().collect();
        slpchars.sort();
        slpword = slpchars.iter().cloned().collect();
        if slword == slpword.to_string() {
            anags.insert(slpword,to_string());
        }
    }
    return anags;
}
