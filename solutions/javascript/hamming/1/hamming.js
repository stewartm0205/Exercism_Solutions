//
// This is only a SKELETON file for the 'Hamming' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export const compute = (a, b) => {
  var ret = 0;
  if (a.length != b.length)
    throw new Error('strands must be of equal length');
  for (var i = 0; i<a.length; i++){
    if (a.charAt(i) != b.charAt(i)) ret++
  }
  return ret;
  //throw new Error('Remove this statement and implement this function');
};
