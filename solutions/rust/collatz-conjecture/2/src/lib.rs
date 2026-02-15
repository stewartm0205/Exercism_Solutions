
pub fn collatz(n: u64) -> Option<u64> {
    let mut s: u64 = 0;
    let mut tn: u64 = n;
    if n == 0 {return None;}
    while tn > 1 {
        if tn%2 == 0 {
            tn = tn / 2;
        } else {
            if tn >= u64::MAX / 3 {
                return None;
            } else {
                tn = 3 * tn + 1;
            }
        }
        s+=1;
    }
    println!("tn={}",tn);
    return Some(s);
}
