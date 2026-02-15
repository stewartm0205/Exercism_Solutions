//
// This is only a SKELETON file for the 'Nucleotide Count' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export function countNucleotides(strand) {
  var a = 0;
  var c = 0
  var g = 0;
  var t = 0;
  for (var ch of strand) {
    switch(ch) {
      case 'A': a++; break;
      case 'C': c++; break;
      case 'G': g++; break;
      case 'T': t++; break;
      default: throw new Error('Invalid nucleotide in strand');
    }
  }
  return `${a} ${c} ${g} ${t}`;
}
