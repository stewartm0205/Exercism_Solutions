#if !defined(WORD_COUNT_H)
#define WORD_COUNT_H
#include <string>
#include <map>
#include <iostream>

using namespace std;
namespace word_count {
    const map<string, int> words(string phrase);
    string get_next_word(string phrase, int* start_pos);
}  // namespace word_count

#endif // WORD_COUNT_H