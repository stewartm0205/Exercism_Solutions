pub fn square(s: u32) -> u64 {
    if s < 1 || s>64 {
        panic!("Square must be between 1 and 64");
    }

    let mut p: u64=1;
    for _n in 2..s+1 {
        p *= 2;
    }
    return p;
}

pub fn total() -> u64 {
    let mut s: u64 = 0;
    for n in 1..65 {
        s += square(n);
    }
    return s;
}
