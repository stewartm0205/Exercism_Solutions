#if !defined(ANAGRAM_H)
#define ANAGRAM_H
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
namespace anagram {
    class anagram {
        private:
            string word;

        public:
            
            anagram(string w): word{w} {};
            vector<string> matches(vector<string> words){
                vector<string> aw={};
                for (auto &w : words) {
                    if (lc_word(word) != lc_word(w) &&
                        sort_word(word) == sort_word(w)) aw.push_back(w);
                }
                    
                return aw;

            }
            string sort_word(string word){
                vector<char> scv; 
                for (size_t i=0; i<word.length(); i++) {
                    scv.push_back(tolower(word.at(i)));
                }
                sort(scv.begin(),scv.end());
                string sword="";
                for(size_t i=0; i<word.length(); i++) {
                    sword+=scv[i];
                }
                return sword;
            } 
            string lc_word(string word){
                string lcw="";
                for (size_t i=0; i<word.length(); i++) {
                    lcw += tolower(word.at(i));
                }
                return lcw;
            } 

    };
}  // namespace anagram

#endif // ANAGRAM_H