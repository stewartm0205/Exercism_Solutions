pub fn nth(n: u32) -> u32 {
	println!("n={}",n);
   let r: Option<u32> = (2..)
	  .filter(|x| is_prime(x))
      .take((n+1) as usize)
      .last();
	  match r {
		  None => return 0 as u32,
		  Some(r) => return r,
	  }
}

pub fn is_prime(n: &u32) -> bool {
	let m = ((*n as f32).sqrt() as u32)+1;
    !(2..m).any(|x| n % x == 0)
}