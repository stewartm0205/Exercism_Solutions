//
// This is only a SKELETON file for the 'Minesweeper' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export const annotate = (input) => {
  var nr = input.length;
  if (nr == 0) return [];
  var nc = input[0].length;
  for (var i=0; i<nr; i++) {
    for (var j=0; j<nc; j++) {
      var m = 0;
      if (input[i][j] == ' '){
        for (var di=-1; di<2; di++) {
          for (var dj=-1; dj<2; dj++){
            if (!(di == 0 && dj == 0) && i+di>=0 && i+di<nr && j+dj>=0 && j+dj<nc) {
              if (input[i+di][j+dj] == '*') {
                m++;
              }
            }
            if (m>0) input[i] = input[i].substring(0,j)+m.toString()+input[i].substring(j+1,);
          }
        }
      }
    }
  }
  return input;
  //throw new Error('Remove this statement and implement this function');
};
