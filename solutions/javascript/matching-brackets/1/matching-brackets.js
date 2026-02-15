//
// This is only a SKELETON file for the 'Matching Brackets' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export const isPaired = (phrase) => {
  phrase = phrase.replace(/[^\]\[\(\)\{\}]+/g,'');
  while(/\(\)|\[\]|\{\}/.test(phrase)) {
    phrase = phrase.replace(/\(\)|\[\]|\{\}/g,'');
  }
  if (phrase == "") return true;
  return false
};
