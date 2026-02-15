//
// This is only a SKELETON file for the 'Protein Translation' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export const translate = (codons) => {
  var protein=[];
  if (!codons) return protein;
  var trans = {'AUG':'Methionine',
  'UUU':'Phenylalanine', 'UUC':'Phenylalanine',
  'UUA':'Leucine', 'UUG':'Leucine',
  'UCU':'Serine', 'UCC':'Serine', 'UCA':'Serine', 'UCG':'Serine',
  'UAU':'Tyrosine', 'UAC':'Tyrosine',
  'UGU':'Cysteine', 'UGC':'Cysteine',
  'UGG':'Tryptophan',
  'UAA':'STOP', 'UAG':'STOP', 'UGA':'STOP'};
  for (let i = 0; 3*i<codons.length; i++){
    var codon = codons.substring(3*i,3*i+3);
    if (codon in trans) {
      if (trans[codon] == 'STOP') return protein;
      protein.push(trans[codon])
    } else {
      throw new Error('Invalid codon');
    }
  }
  return protein;
};
