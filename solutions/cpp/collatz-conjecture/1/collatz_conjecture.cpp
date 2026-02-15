#include "collatz_conjecture.h"

namespace collatz_conjecture {
    int steps(int number) {
        if (number <= 0) throw std::domain_error("error");
        int s = 0;
        while (number > 1) {
            if (number % 2 ==0) number /= 2;
            else number = 3 * number + 1;
            s++;
        }
        return s;
    }
}  // namespace collatz_conjecture
