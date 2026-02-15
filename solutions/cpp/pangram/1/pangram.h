#if !defined(PANGRAM_H)
#define PANGRAM_H
#include <string.h>
#include <ctype.h>
#include <iostream>

using namespace std;
namespace pangram {
    bool is_pangram (const char*  sentence);
}  // namespace pangram

#endif // PANGRAM_H