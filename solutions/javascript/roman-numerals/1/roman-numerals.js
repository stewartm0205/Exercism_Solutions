//
// This is only a SKELETON file for the 'Roman Numerals' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export const toRoman = (number) => {
  var rom_cnv = {1000:"M", 900: "CM", 500: "D", 400: "CD",
  100: "C", 90:"XC", 50: "L", 40: "XL",
  10: "X", 9: "IX", 5:"V", 4: "IV", 1:"I"};
  var rev = Object.keys(rom_cnv).reverse();
  var result = "";
  while (number > 0) {
    for (var ki=0; ki<rev.length;ki++){
      var key = rev[ki];
      while (key <= number) {
        var value = rom_cnv[key];
        result += value;
        number = number - key;
      }
    }
  }
  return result;
  //throw new Error('Remove this statement and implement this function');
};
