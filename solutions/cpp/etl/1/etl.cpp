#include "etl.h"
using namespace std;
namespace etl {
   map<char, int> transform(map<int, std::vector<char>> old){
       map<char, int> newdic;
       for (auto const& x : old) {
           auto score = x.first;
           auto chs = x.second;
           for (auto const& y : chs) {
               newdic[tolower(y)]=score;
           }
       }
       return newdic;
   }
}  // namespace etl
