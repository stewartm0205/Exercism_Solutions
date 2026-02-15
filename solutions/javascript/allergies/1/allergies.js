//
// This is only a SKELETON file for the 'Allergies' exercise. It's been provided as a
// convenience to get you started writing code faster.
//
const ALNAMES= ['eggs', 'peanuts', 'shellfish','strawberries', 'tomatoes','chocolate','pollen','cats'];

export class Allergies {
  constructor(aln) {
    this.aln = aln;
  }

  list() {
    var i=[];
    var n = this.aln;
    for (var j=0; j <= 7 ; j++) {
      i.push(n % 2);
      n = Math.floor(n / 2);
    }
    var alleg = [];
    for (var j=0; j <= 7 ; j++) {
      if (i[j] == 1) alleg.push(ALNAMES[j]);
    }
    return alleg;
  }

  allergicTo(alname) {
    if (this.list().indexOf(alname)>=0)
      return true;
    return false;
  }
};
