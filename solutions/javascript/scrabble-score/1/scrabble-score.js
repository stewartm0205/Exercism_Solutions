//
// This is only a SKELETON file for the 'Scrabble Score' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export const score = (word) => {
  var score = 0;
  for (var ch of word) {
    if ('A, E, I, O, U, L, N, R, S, T'.indexOf(ch.toUpperCase())>=0) score += 1;
    if ('D, G'.indexOf(ch.toUpperCase())>=0) score += 2;
    if ('B, C, M, P'.indexOf(ch.toUpperCase())>=0) score += 3;
    if ('F, H, V, W, Y'.indexOf(ch.toUpperCase())>=0) score += 4;
    if ('K'.indexOf(ch.toUpperCase())>=0) score += 5;
    if ('J, X'.indexOf(ch.toUpperCase())>=0) score += 8;
    if ('Q, Z'.indexOf(ch.toUpperCase())>=0) score += 10;
  }
  return score;
  //throw new Error('Remove this statement and implement this function');
};
