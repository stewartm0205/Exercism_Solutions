//
// This is only a SKELETON file for the 'Transpose' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

import { rawListeners } from "process";

export const transpose = (lines) => {
  var trl = []
  if (lines.length==0) return [];
  var nr=lines.length;
  var ml=0;
  for (var r =0; r <nr; r++) {
    if (lines[r].length>ml) ml = lines[r].length;
  }
  for (var r =0; r <nr; r++) {
    if (lines[r].length<ml) lines[r]+=' '.repeat(ml-lines[r].length);
  }
  for (var r = 0; r < nr; r++) {
    for (var c = 0; c < lines[r].length; c++) {
      if (r==0) {
        trl.push(lines[r][c]);
      } else {
        trl[c]=trl[c].substring(0,r)+lines[r][c]+trl[c].substring(r+1,)
      }
    }
  }
  trl[trl.length-1]=trl[trl.length-1].trimEnd();
  return trl;
};
