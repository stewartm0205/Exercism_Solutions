#if !defined(BEER_SONG_H)
#define BEER_SONG_H
#include <string>
using namespace std;

namespace beer_song {
    string verse(int n);
    string sing(int b, int e);
    string sing(int b);
}  // namespace beer_song

#endif // BEER_SONG_H