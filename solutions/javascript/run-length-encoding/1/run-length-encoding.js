//
// This is only a SKELETON file for the 'Run Length Encoding' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export const encode = (phrase) => {
  var code = "";
  var pi = 0;
  var ch = "";
  var nc = "";
  while (pi<phrase.length) {
    ch = phrase.substring(pi,pi+1);
    var n = 1;
    pi++;
    nc = phrase.substring(pi,pi+1);
    while (nc == ch & pi<phrase.length) {
      n++;
      pi++;
      nc = phrase.substring(pi,pi+1);
    }
    if (n>1) {
      code += n.toString()+ch;
    } else {
      code +=ch;
    }
  }
  return code;
  //throw new Error('Remove this statement and implement this function');
};

export const decode = (code) => {
  var phrase = "";
  var ci = 0;
  var ch = "";
  var n = 0;
  while (ci < code.length) {
    ch = code.substring(ci,ci+1);
    var nstr = '';
    while (ch >= '0' && ch <= '9') {
      nstr += ch;
      ci++;
      ch = code.substring(ci,ci+1);
    }
    if (nstr.length>0){
      n=parseInt(nstr);;
      phrase += ch.repeat(n);
    } else {
      phrase += ch;
    }
    ci++;

  }
  //throw new Error('Remove this statement and implement this function');
  return phrase;
};
