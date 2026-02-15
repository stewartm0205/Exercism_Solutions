/**
 * You can use the bigint type and BigInt global object to support numbers below
 * Number.MIN_SAFE_INTEGER and above NUMBER.MAX_SAFE_INTEGER.
 *
 * https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/BigInt
 */

//
// This is only a SKELETON file for the 'Grains' exercise. It's been provided as a
// convenience to get you started writing code faster.
//
export const square = (n) => {
  if (n < 1 || n > 64) throw new Error('square must be between 1 and 64');
  var sn = BigInt(1);
  for (var i=2; i<=n; i++){
    sn = sn * BigInt(2);
  }
  return sn;
};

export const total = () => {
  var s = BigInt(0);
  for (var i=1; i<= 64; i++) {
    s += square(i);
  }
  return s;
};
