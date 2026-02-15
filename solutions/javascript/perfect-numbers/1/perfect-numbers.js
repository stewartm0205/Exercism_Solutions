
export const classify = (num) => {
  if (num <= 0)
    throw new Error('Classification is only possible for natural numbers.');
  var fact = factors(num);
  if (num != 1 && sum(fact) === num) return "perfect"
  if (sum(fact) > num) return "abundant"
  if (num === 1 || sum(fact) < num) return "deficient"
};
function factors(num){
  var ret = new Array();
  ret.push(1);
  for (var i=2;i<num;i++) {
    if (num % i == 0) ret.push(i);
  }
  return ret;
}
function sum(factors){
  var ret = 0;
  factors.forEach(fact => ret += fact);
  return ret;
}