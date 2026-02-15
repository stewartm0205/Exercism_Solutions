#include "difference_of_squares.h"

namespace difference_of_squares {
    int square_of_sum(int n) {
        int s=0;
        for (int i=1; i<=n; i++) {
            s+=i;
        }
        return s*s;
    }
    int sum_of_squares(int n) {
        int s=0;
        for (int i=1; i<=n; i++) {
            s+=i*i;
        }
        return s;
    }
    int difference(int n) {
        return square_of_sum(n) - sum_of_squares(n);
    }
}  // namespace difference_of_squares
