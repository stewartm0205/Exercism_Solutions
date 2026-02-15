
var DnaTranscriber = function () {
};

DnaTranscriber.prototype.toRna = function (dna) {
    dnacode="GCTA";
    rnacode="CGAU";
    var rna =""
    for (var i = 0; i<dna.length; i++) {
        var j = dnacode.indexOf(dna.substring(i,i+1));
        if (j < 0) {
            throw new Error('Invalid input');
        }
        rna = rna + rnacode.substring(j,j+1);
    }  
    return rna;
};

module.exports = DnaTranscriber;
