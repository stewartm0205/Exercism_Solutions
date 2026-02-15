// This stub file contains items which aren't used yet; feel free to remove this module attribute
// to enable stricter warnings.
#![allow(unused)]

use std::collections::HashMap;

pub fn can_construct_note(magazine: &[&str], note: &[&str]) -> bool {
    let mut mw = HashMap::new();
    let mut nw = HashMap::new();
    for w in magazine {
        let c = mw.entry(w).or_insert(0);
        *c += 1;
    }
    for w in note {
        let c = nw.entry(w).or_insert(0);
        *c += 1;
    }
    for (w, c) in nw.iter() {
        if !mw.contains_key(w) {
            return false;
        }
        if mw.get(w) < Some(c) {
            return false;
        }
    }
    return true;
}
