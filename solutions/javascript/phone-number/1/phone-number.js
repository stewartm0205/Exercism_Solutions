//
// This is only a SKELETON file for the 'Phone Number' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export const clean = (phone) => {
  phone=phone.replace(/[-+.\(\) ]/g,'');
  if (phone.length == 9) throw new Error('Incorrect number of digits');
  if (phone.length > 11)
  throw new Error('More than 11 digits');
  if (phone.length == 11 && phone.charAt(0) != '1')
  throw new Error('11 digits must start with 1');
  if (phone.length == 11) phone = phone.substring(1);
  if (phone.match(/[a-z]/)) throw new Error('Letters not permitted');
  if (phone.match(/[@:!]/)) throw new Error('Punctuations not permitted');
  var p1 = phone.substring(0,3);
  var p2 = phone.substring(3,6);
  var p3 = phone.substring(6);
  if (p1.substring(0,1) == '0') throw new Error('Area code cannot start with zero');
  if (p1.substring(0,1) == '1') throw new Error('Area code cannot start with one');
  if (p2.substring(0,1) == '0') throw new Error('Exchange code cannot start with zero');
  if (p2.substring(0,1) == '1') throw new Error('Exchange code cannot start with one');
  return phone
};
