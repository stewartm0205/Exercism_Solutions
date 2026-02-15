pub fn sum_of_multiples(limit: u32, factors: &[u32]) -> u32 {
   let mut s :u32 = 0;
    for n in 1..limit {
       for f in factors {
           if f != &0  {
                if n%f == 0 {
                    s = s + n;
                    break;
                }
            }
       }
   }
   return s;
}
