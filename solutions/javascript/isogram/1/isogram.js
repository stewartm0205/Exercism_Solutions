//
// This is only a SKELETON file for the 'Isogram' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export const isIsogram = (word) => {
  var wc = {}
  for (var ch of word.toLowerCase()) {
    if (ch.match(/[a-zA-z]/)) {
      if (ch in wc) return false;
      else wc[ch] = 1;
    }
  }
  return true

};
