pub fn build_proverb(list: &[&str]) -> String {
    let mut p: String = "".to_string();
    if list.len() == 0 { return p};
    for i in 0..list.len()-1 {
        p = p + &format!("For want of a {0} the {1} was lost.\n",list[i],list[i+1]).to_string();
    }
    p = p + &format!("And all for the want of a {}.",list[0]).to_string();
    return p;
}
