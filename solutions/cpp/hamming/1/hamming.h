#if !defined(HAMMING_H)
#define HAMMING_H
#include <string.h>
#include <exception>
#include <stdexcept>

namespace hamming {
int compute(const char* s1, const char* s2);
}  // namespace hamming

#endif // HAMMING_H