use std::convert::TryFrom;
pub fn nth(n: u32) -> u32 {
    //println!("n={}",n);
    let mut p: [u32;11_000] = [0;11_000];
    //p[0] = 2;
    let mut pl: usize = 0;
    let mut i: u32 = 2;
    let mut pi: usize;
    while i <= 110_000 {
        //println!("i={}",i);
        pi = 0;
        while pi < pl {
            if i % p[pi] == 0 {
                break;
            }
            pi = pi +1;
        }
        //println!("pi={}",pi);
        //println!("pl={}",pl);
        if pi == pl {
            p[pl] = i;
            if u32::try_from(pl) == Ok(n) {
                return i;
            }
            pl = pl + 1;
        }
        i = i+1;
    }
    return i;
}

