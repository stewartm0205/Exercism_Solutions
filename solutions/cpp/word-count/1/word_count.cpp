#include "word_count.h"
using namespace std;
namespace word_count {
    const map<string, int> words(string phrase) {
        map<string, int> wc;
        int start_pos = 0;
        string word;
        while (start_pos < (int)phrase.length()){
            word = get_next_word(phrase, &start_pos);

            if (word != "") {
                if(wc.find(word) == wc.end()) {
                    wc[word]=1;
                   
                } else {
                    wc[word]++;
                    
                }
            }
        }
   
        return wc;
    }
    string get_next_word(string phrase, int* start_pos) {
        string ws = " ,.\n\t!&@$%^:";
        int pos;

        /* skip white spaces */
        for (pos = *start_pos; pos<(int)phrase.length(); pos++) {
            if (ws.find(phrase.substr(pos,1))>=phrase.length()) break;
        }
        
        /* get next word */
        string next_word = "";
        for(;pos<(int)phrase.length(); pos++){
            if (ws.find(phrase.substr(pos,1))<phrase.length()) break;
            next_word += phrase.substr(pos,1);
            
        }

        *start_pos = pos;
        string lc_next_word="";
        for(int i=0; i<(int)next_word.length(); i++) {
            lc_next_word+=tolower(next_word.at(i));
        }
        if (lc_next_word.substr(0,1)=="'")lc_next_word=lc_next_word.substr(1,lc_next_word.length()-2);
        //if (lc_next_word.substr(lc_next_word.length()-1,1)=="'")lc_next_word=lc_next_word.substr(0,lc_next_word.length()-1);
        return lc_next_word;
    }   
}  // namespace word_count
