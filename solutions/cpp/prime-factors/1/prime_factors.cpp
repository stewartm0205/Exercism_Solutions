#include "prime_factors.h"
using namespace std;
namespace prime_factors {
    vector<int> of(int n) {
        vector<int> p = {};
        vector<int> pf = {};
        if (n==1) return pf;
        for (int i=2; i<=n; i++) {
            int j;
            for (j=0; j<(int)p.size();j++) {
                if (i % p[j]==0) break;
            }
            if (j==(int)p.size()) {
                p.push_back(i);
                while (n % i == 0) {
                    pf.push_back(i);
                    n = n / i; 
                }
            }
        }
        return pf;    
    }
}  // namespace prime_factors
