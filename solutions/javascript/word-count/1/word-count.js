//
// This is only a SKELETON file for the 'Word Count' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export const countWords = (phrase) => {
  var wc={};
  var nphrase = phrase.toLowerCase().replace(/[:!&@$%^&.]+/g,'').replace(/  /g," ").trim();
  var words = nphrase.split(/[ \n\t,]+/);
  for (var wi =0; wi < words.length; wi++) {
    words[wi]=words[wi].replace(/^["']*|["']*$/g,'')
    if (words[wi] != "") {
      if (words[wi] in wc) {
        wc[words[wi]]++;
      } else {
        wc[words[wi]] = 1;
      }
    }
  }
  return wc;
};
