#if !defined(ATBASH_CIPHER_H)
#define ATBASH_CIPHER_H
#include <string>
#include <ctype.h>
#include <iostream>
using namespace std;
namespace atbash_cipher {
    string encode(string phrase);
    string decode(string code);
}  // namespace atbash_cipher

#endif // ATBASH_CIPHER_H