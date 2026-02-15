//
// This is only a SKELETON file for the 'Luhn' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export const valid = (num) => {
  num = num.replace(/[ .]/g,'');
  if (num.length <= 1) return false;
  var s = 0;
  var sd = 1;
  var n;
  for (var i=num.length-1; i>=0; i--) {
    if (sd == 2) {
      n = 2 * parseInt(num.substr(i,1));
      if (n > 9) n = n -9;
      sd = 1;
    } else {
      n = parseInt(num.substr(i,1));
      sd = 2;
    }
    s += n;
  }
  if (s % 10 == 0) return true;
  return false;
};
