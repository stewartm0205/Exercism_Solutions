#if !defined(NUCLEOTIDE_COUNT_H)
#define NUCLEOTIDE_COUNT_H
#include <map>
#include <string.h>
using namespace std;
namespace nucleotide_count {
class dna {
    private: 
        char* dna_strand;
    public:
    dna (char* &counter) :dna_strand(counter){};
    ~dna(){};
    char* counter(char* strand) { return strand;}
    int count(char d) {
        int c=0;
        for (size_t i= 0; i<strlen(dna_strand); i++) {
            if (d==dna_strand[i]) c++;
        }
        return c;    
    }
    map<char, int> nucleotide_counts(){
        map<char, int> dc;
        for (size_t i= 0; i<strlen(dna_strand); i++) {
            char ch = dna_strand[i];
            if (dc.find(ch)==dc.end()) dc[ch] = 1;
            else dc[ch]++;
        }
        return dc;
    }
};
}  // namespace nucleotide_count

#endif // NUCLEOTIDE_COUNT_H