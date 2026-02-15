#include "acronym.h"
using namespace std;
namespace acronym {
    string acronym(string phrase) {
        regex w = regex("([^ ,-]*)[ ,-]*([^ ,-]*)[ ,-]*([^ ,-]*)[ ,-]*([^ ,-]*)");
        smatch words;
        if (regex_search(phrase,words,w)) {
            string a ="";
            for (int i=1; i <=(int)words.size(); i++) {
                string word=words[i];
                if (word!="") {
                    a+= toupper(word.at(0));
                } 
            }
            return a;
        }
        return "";

    }
}  // namespace acronym
