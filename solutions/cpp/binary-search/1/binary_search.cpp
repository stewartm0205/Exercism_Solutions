#include "binary_search.h"
using namespace std;
namespace binary_search {
    size_t find(vector<int> data, int item){
        size_t b;
        size_t m;
        size_t e;
        if (data.size()==0)throw domain_error(" ");
        b=0; 
        e=data.size()-1;
        m=(b+e)/2;
        while (true){
            if (item==data[e]) return e;
            if (item==data[m]) return m;
            if (item<data[b]) throw domain_error(" ");
            if (item>data[e]) throw domain_error(" ");
            if (e-b== 1 && item>data[b]&& item<data[e]) throw domain_error(" ");
            if (item<=data[m]) e=m;
            if (item>data[m]) b=m;
            m=(b+e)/2;
        }

    }
}  // namespace binary_search
