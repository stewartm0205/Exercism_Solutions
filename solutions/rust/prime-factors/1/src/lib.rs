pub fn factors(n: u64) -> Vec<u64> {
    let mut fs = Vec::<u64>::new();
    let mut r = n;
    let mut f = 2;
    while r>1 {
        if r%f == 0 {
            fs.push(f);
            r = r/f;
        } else {
            f = f+1;
        }
    }
    return fs;
}
