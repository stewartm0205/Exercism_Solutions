//
// This is only a SKELETON file for the "Leap" exercise. It's been provided as a
// convenience to get you started writing code faster.
//

var DnaTranscriber = function () {
	//this.dna = dna;
};

DnaTranscriber.prototype.toRna = function (dna) {
var rna =""
for (var i = 0; i<dna.length; i++) {
	switch(dna.substring(i,i+1)) {
	  case "G": 
	    rna = rna + "C";
	    break;
	  case "C": 
	    rna = rna + "G";
	    break;
	  case "T": 
	    rna = rna + "A";
	    break;
	  case "A": 
	    rna = rna + "U";
	   break;
	   default:
		throw new Error('Invalid input');
	}	
}	

return rna;

};

module.exports = DnaTranscriber;
