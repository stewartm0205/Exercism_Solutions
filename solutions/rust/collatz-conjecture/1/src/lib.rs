
pub fn collatz(n: u64) -> Option<u64> {
    let mut s: u64 = 0;
    let mut tn: u64 = n;
    if n == 0 {return None;}
    while tn > 1 {
        if tn%2 == 0 {
            tn /= 2;
        } else {
            match tn.checked_mul(3) {
                None => return None,
                Some(y)=> y,
            };
            match tn.checked_add(1) {
                None => return None,
                Some(y) => y,
            };
            //tn = 3 * tn + 1;
        }
        s+=1;
    }
    return Some(s);
}
