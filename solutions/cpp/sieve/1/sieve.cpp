#include "sieve.h"
using namespace std;

namespace sieve {
    vector<int> primes(int n) {
        vector<int> p = {};
        if (n==1) return p;
        for (int i=2; i<=n; i++) {
            int j;
            for (j=0; j<(int)p.size();j++) {
                if (i % p[j]==0) break;
            }
            if (j==(int)p.size()) p.push_back(i);
        }
        return p;
    }
}  // namespace sieve
