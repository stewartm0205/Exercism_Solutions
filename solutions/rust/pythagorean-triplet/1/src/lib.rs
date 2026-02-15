

pub fn find() -> Option<u32> {
    for a in 1..999 {
		for b in 1..(999 - a) {
			let c = 1000 - (a+b);
			//println!("a={},b={},c={}",a,b,c);
			if a*a + b*b == c*c {
				return Some(a * b * c);
			}
		}
	}
	return None;
}
