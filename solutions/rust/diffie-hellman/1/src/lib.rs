pub fn private_key(p: u64) -> u64 {
    return 3;
}

pub fn public_key(p: u64, g: u64, a: u64) -> u64 {
    println!("p={},g={},a={}",p,g,a);
    println!("pk={}",exp(g,a));
    return exp(g,a) % p;
}

pub fn secret(p: u64, b_pub: u64, a: u64) -> u64 {
    return exp(b_pub,a) % p;
}

pub fn exp(n: u64, p: u64) -> u64 {
    let mut rs :u64 = n;
    let mut pi :u64 = p;
    while pi > 1 {
        rs = rs * n;
        pi -= 1;
        println!("rs={},pi={}",rs,pi);
    }
    return rs;
}
