#include "nth_prime.h"
using namespace std;
namespace nth_prime {
    int nth(int n){
        if (n==0) throw std::domain_error("invalid argument");
        vector<int> p = {};
        int i;
        for (i=2; ; i++) {
            int j;
            for (j=0; j<(int)p.size();j++) {
                if (i % p[j]==0) break;
            }
            if (j==(int)p.size()) p.push_back(i);
            if ((int)p.size()==n) return p[j];
        }
        //return i;
    }
}  // namespace nth_prime
