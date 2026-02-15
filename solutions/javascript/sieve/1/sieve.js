//
// This is only a SKELETON file for the 'Sieve' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export const primes = (n) => {
  if (n <= 1) return [];
  var pr = [2];
  for (var p = 3; p <= n; p=p+2) {
    var i;
    for (i = 1; i <= pr.length; i++) {
      if (p % pr[i] == 0) break;
    }
    if (i > pr.length) pr.push(p);
  }
  return pr;
};
