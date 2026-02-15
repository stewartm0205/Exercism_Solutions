
//use std::collections::HashSet;
#[derive(Debug, Eq, PartialEq)]
pub enum Comparison {
    Equal,
    Sublist,
    Superlist,
    Unequal,
}

pub fn sublist<T: PartialEq>(_first_list: &[T], _second_list: &[T]) -> Comparison {

    if _first_list.len() == 0 && _first_list.len() == _second_list.len() {
        return Comparison::Equal;
    }
    if _first_list.len() == _second_list.len() && _first_list == _second_list {
        return Comparison::Equal;
    }
    if _first_list.len() > 0 && _second_list.len() == 0 {
        return Comparison::Superlist;
    }
    if _first_list.len() == 0 && _second_list.len() > 0 {
        return Comparison::Sublist;
    }
    if _first_list.len() < _second_list.len() {
        if is_sublist(_first_list, _second_list) {
            return Comparison::Sublist;
        }
    }
    if _first_list.len() > _second_list.len() {
        if is_sublist(_second_list, _first_list) {
            return Comparison::Superlist;
        }
    }

    return Comparison::Unequal;
}

pub fn is_sublist<T: PartialEq>(listsub: &[T], listsuper: &[T]) -> bool {
    // first sublist
    let mut i = 0;
    let mut j = 0;
    while i < listsub.len() && j < listsuper.len() {
       // println!("i={},j={}",i,j);
        if listsub[i] == listsuper[j] {
            if i == listsub.len() - 1 {return true};
            i+=1;
            j+=1;
        } else {
            j = (j - i) + 1;
            i = 0;
        }
    }
    return false;
}
