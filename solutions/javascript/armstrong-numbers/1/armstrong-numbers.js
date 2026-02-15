//
// This is only a SKELETON file for the 'Armstrong Numbers' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export const isArmstrongNumber = (num) => {
  var digits = num.toString();
  var nd = digits.length;
  var s = 0;
  for (var i=0; i<nd; i++) {
    s += parseInt(digits.charAt(i)) ** nd;
  }
  if (s == num) return true;
  return false;
};
