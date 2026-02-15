pub fn find_saddle_points(input: &[Vec<u64>]) -> Vec<(usize, usize)> {
	let mut sps = Vec::new();
	println!("size={},{}",input.len(),input[0].len());
	//for r in 0..(input.len()-1)
	for r in 0..input.len()	{
		for c in 0..input[0].len() {
		
			let mut sp = input[r][c]; 
			println!("r={},c={}, sp={}", r, c, sp);
			let mut spi = 1;
			for spr in 0..input.len() {
				println!("spr={},input[{}][{}]={} ", spr, spr, c,  input[spr][c]);
				if r != spr && input[spr][c] < sp {spi=0; println!("spi={}", spi); break}
			}
			for spc in 0..input[r].len() {
				println!("spc={},input[{}][{}]={} ", spc, r, spc, input[r][spc]);
				if c != spc && input[r][spc] > sp {spi=0; println!("spi={}", spi); break}
			}
			if spi == 1 {println!("spi={}", spi); sps.push((r, c))}
		}
    }
	return sps;
}

