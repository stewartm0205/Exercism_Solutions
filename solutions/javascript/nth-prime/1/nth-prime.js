//
// This is only a SKELETON file for the 'Nth Prime' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export const prime = (n) => {
  if (n == 0)
  throw new Error('there is no zeroth prime');
  if (n == 1) return 2;
  var pr = [2];
  for (var p = 3;; p=p+2) {
    var i;
    for (i = 1; i <= pr.length; i++) {
      if (p % pr[i] == 0) break;
    }
    if (i > pr.length) pr.push(p);
    if (n == pr.length) return p;
  }
};