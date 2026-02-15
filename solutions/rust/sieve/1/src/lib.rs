pub fn primes_up_to(upper_bound: u64) -> Vec<u64> {
    let res: Vec<u64> = (2..upper_bound+1)
    .filter(|x| is_prime(x)).collect();
    return res;
}
pub fn is_prime(n: &u64) -> bool {
	let m = ((*n as f64).sqrt() as u64)+1;
    !(2..m).any(|x| n % x == 0)
}