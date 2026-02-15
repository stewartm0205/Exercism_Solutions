#include "atbash_cipher.h"
using namespace std;
namespace atbash_cipher {
    string encode(string phrase){
        string alpha = "abcdefghijklmnopqrstuvwxyz";
        string rev_alpha ="";
        for (int i=25; i>=0; i--){
            rev_alpha+=alpha.substr(i,1);
        } 
        string code="";
        int c = 0;
        for (int i=0;i<(int)phrase.length();i++) {
            if (phrase.substr(i,1) != " " &&
                phrase.substr(i,1) != "," &&
                phrase.substr(i,1) != ".") 
            {
                if (phrase.substr(i,1)>="0" && 
                    phrase.substr(i,1)<="9") {
                    code+=phrase.substr(i,1);
                } else {
                    char lch = tolower(phrase.at(i));
                    string ch = "";
                    ch += lch;
                    int pos = alpha.find(ch);
                    string cch = rev_alpha.substr(pos,1);
                    code+=cch;
                }  
                if (c<4) c++;
                else {
                    code+=" ";
                    c = 0;
                }  
            }
        }
        if (code.substr(code.length()-1,1)==" ") 
            code = code.substr(0,code.length()-1);
        return code;
    }
    string decode(string code) {
        string alpha = "abcdefghijklmnopqrstuvwxyz";
        string rev_alpha ="";
        for (int i=25; i>=0; i--){
            rev_alpha+=alpha.substr(i,1);
        } 
        string phrase ="";
        for (int i=0;i<(int)code.length();i++) {
            if (code.substr(i,1) != " ") {
                if (code.substr(i,1)>="0" && 
                    code.substr(i,1)<="9") {
                    phrase+=code.substr(i,1);
                } else {
                    string cch = code.substr(i,1);
                    int pos = rev_alpha.find(cch);
                    string ch = alpha.substr(pos,1);
                    phrase+=ch;
                }
            }
        }
        return phrase;
    }
}  // namespace atbash_cipher
