//
// This is only a SKELETON file for the 'ETL' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export const transform = (olddict) => {
  var newdict = {};
  letters = [];
  for (var value in olddict) {
    var letters = olddict[value];
    for (var i=0; i<letters.length; i++) {
      var letter = letters[i];
      newdict[letter.toLowerCase()] = parseInt(value);
    }
  }

  return newdict;
};
