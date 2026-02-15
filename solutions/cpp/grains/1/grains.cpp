#include "grains.h"

namespace grains {
    unsigned long long square (int n) {
        unsigned long long p = 1;
        for (int i=1; i<n; i++) {
            p *= 2;
        }
        return p;
    }
    unsigned long long total () {
        unsigned long long t = 0;
        for (int i=1; i<=64; i++) {
            t+=square(i);
        }
        return t;
    }
}  // namespace grains
