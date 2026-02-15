//
// This is only a SKELETON file for the 'Reverse String' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export const reverseString = (str) => {
  var ret = '';
  for(var i=str.length;i>=0;i--) ret+=str.charAt(i);
  return ret;
};
