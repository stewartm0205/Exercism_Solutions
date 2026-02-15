use std::convert::TryInto;
pub fn is_armstrong_number(num: u32) -> bool {
	let mut tnum: u32 = num;
	let nd: u32 = tnum.to_string().len().try_into().unwrap();
	let mut s: u32 = 0;
	for _di in 1..(nd+1) {
		s += (tnum%10).pow(nd);
		tnum/=10;
	}
	if s == num {
		return true;
	} else {
		return false;
	}
}
