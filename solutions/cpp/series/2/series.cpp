#include "series.h"
using namespace std;
namespace series {
    vector<int> digits(string d){
        vector<int> dgs={};
        for (int i=0; i<(int)d.length(); i++) {
            dgs.push_back(d.at(i)-'0');
        }
        return dgs;
    }
    vector<vector<int>> slice(string d, int size){
        if (size > (int)d.length()) throw std::domain_error("invalid argument");
        vector<vector<int>> s = {};
        for (int i=0; i<(int)d.length()-size+1; i++){
            s.push_back({});
            for (int j=0; j<size; j++) {
                s[i].push_back(d.at(i+j)-'0');
            }
        }
        return s;
    }
    

}  // namespace series
