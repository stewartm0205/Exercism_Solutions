#if !defined(NUCLEOTIDE_COUNT_H)
#define NUCLEOTIDE_COUNT_H
#include <map>
#include <string.h>
#include <stdexcept>
#include <iostream>
using namespace std;
namespace nucleotide_count {
class counter {
    private: 
        map<char, int> counts;
    public:
        counter (const string &s) noexcept(false) : counts({{'A',0},{'C',0},{'G',0},{'T',0}})
        {            
            for (auto &c: s) {
                if (counts.find(c) == counts.end()) throw invalid_argument("error");
                counts.at(c) += 1;
            }
        }
        ~counter(){};
        int count(const char &c) const {
            if (counts.find(c) == counts.end()) throw invalid_argument("error");
            return counts.at(c);    
        }
        const map<char, int> nucleotide_counts() const {
            return counts;
        }
};
}  // namespace nucleotide_count

#endif // NUCLEOTIDE_COUNT_H