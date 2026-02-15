
var Cipher = function (key) {
    this.alpha = 'abcdefghijklmnopqrstvuwxyz';
    if (key == '') {
        throw new Error('Bad key');
    }
    if (key) {
        this.key = key;
        for (var i = 0; i<10; i++) {
            if (key.substring(i, i+1) >= 'A' && key.substring(i, i+1) <= 'Z') {
                throw new Error('Bad key');
            }
            if (key.substring(i, i+1) >= '0' && key.substring(i, i+1) <= '9') {
                throw new Error('Bad key');
            }
        }
    } else {
        key = "";
        for (var i = 0; i<10; i++) {
            ai = Math.floor(Math.random()*26);
            this.key = this.key + this.alpha.substring(ai, ai+1);
        }
    }
    kl = key.length;
};

Cipher.prototype.encode = function (sentence) {
    var code =""
    var ki=0;
    var sl=sentence.length;
    for (var i = 0; i<sl; i++) {
        code = code + this.alpha.substring(this.alpha.indexOf(this.key.substring(ki,ki+1)));
        ki++;
        if (ki > this.kl) ki = 0;
    }  
    return code;
};

Cipher.prototype.decode = function (code) {
    var sentence = "";
    var ki = 0;
    var cl = code.length;
    for (var i = 0; i<cl; i++) {
        sentence = sentence + this.alpha.substring(this.alpha.indexOf(this.key.substring(ki,ki+1)));
        ki++;
        if (ki > this.kl) ki = 0;
    }  
    return sentence;
};

module.exports = Cipher;
