//
// This is only a SKELETON file for the 'All Your Base' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export const convert = (digits,frombase,tobase) => {
  if (frombase <=1 ) throw new Error('Wrong input base');
  if (tobase <=1 ) throw new Error('Wrong output base');
  if (digits == undefined)
  throw new Error('Input has wrong format');
  if (digits.length == 0)
  throw new Error('Input has wrong format');
  if (digits.length >=2 && digits[0] == 0)
  throw new Error('Input has wrong format');
  if (digits.length==1 & digits[0] == 0) return [0];
  var num=0;
  var base = 1;
  for (var di = digits.length-1; di>=0; di--) {
    if (digits[di]<0) throw new Error('Input has wrong format');
    if (digits[di]>=frombase) throw new Error('Input has wrong format');
    num += (digits[di] * base);
    base *= frombase;
  }
  var newnum = [];
  while (num >= 1){
    newnum.unshift(num % tobase);
    num = Math.floor(num / tobase);
  }
  return newnum;
};
