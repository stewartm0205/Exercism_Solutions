//
// This is only a SKELETON file for the 'Prime Factors' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export const primeFactors = (n) => {
  if (n<=1) return [];
  var pf=[];
  for (var f = 2; f<=n; f++) {
    var i;
    for (i = 0; i<pf.length; i++) {
      if (f % pf[i] == 0) break;
    }
    if (i==pf.length && n % f == 0) {
      pf.push(f);
      n = n / f;
      while (n % f == 0) {
        pf.push(f)
        n = n / f;
      }
    }
  }
  return pf;
  //throw new Error('Remove this statement and implement this function');
};
