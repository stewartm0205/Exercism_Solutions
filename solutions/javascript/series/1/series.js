//
// This is only a SKELETON file for the 'Series' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export class Series {
  constructor(series) {
    if (series == '') throw new Error('series cannot be empty');
    this.series = series;
  }

  slices(sliceLength) {
    if (sliceLength < 0) throw new Error('slice length cannot be negative');
    if (sliceLength == 0) throw new Error('slice length cannot be zero');
    if (sliceLength > this.series.length) throw new Error('slice length cannot be greater than series length');
    var sll = [];
    for (var i=0; i <= this.series.length - sliceLength; i++ ) {
      var sl = []
      for (var j=0; j<sliceLength; j++) {
        var n = parseInt(this.series.substr(i+j,1))
        sl.push(n);
      }
      sll.push(sl);
    }
    return sll;
  }
}
