//
// This is only a SKELETON file for the 'Raindrops' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export const convert = (num) => {
  var ret = ''
  if (num % 3 == 0) ret += 'Pling';
  if (num % 5 == 0) ret += 'Plang';
  if (num % 7 == 0) ret += 'Plong';
  if (ret == '') ret += num.toString();
  return ret;
};
