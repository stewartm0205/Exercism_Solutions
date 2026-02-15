//
// This is only a SKELETON file for the 'Anagram' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export const findAnagrams = (word, wordlist) => {
  word=word.toLowerCase(word);
  var anawords=[];
  for (var wi=0; wi < wordlist.length; wi++){
    if (word.length != wordlist[wi].length) continue;
    if (word == wordlist[wi].toLowerCase()) continue;
    if (word.split('').sort().join('') ==
        wordlist[wi].toLowerCase().split('').sort().join('')) {
          anawords.push(wordlist[wi]);
        }
  }
  return anawords;
};
