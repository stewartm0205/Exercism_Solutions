use std::collections::HashSet;

pub fn anagrams_for<'a>(word: &str, possible_anagrams: &[&'a str]) -> HashSet<&'a str> {
    return possible_anagrams
    .iter()
    .cloned()
    .filter(|pw| sort_lc(pw)==sort_lc(word)&&
    pw.to_lowercase()!=word.to_lowercase())
    .collect();
}

pub fn sort_lc(word: &str) -> String {
    let mut slchars: Vec<char> = word.to_lowercase().chars().collect();
    slchars.sort_by(|a,b| a.cmp(b));
    let slword: String = slchars.iter().collect();
    return slword;
}
