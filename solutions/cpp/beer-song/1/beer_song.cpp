#include "beer_song.h"
using namespace std;
namespace beer_song {
    string verse(int n) {
        char v[160] = "";
        if (n>2) 
            sprintf(v,"%d bottles of beer on the wall, %d bottles of beer.\n"
        "Take one down and pass it around, %d bottles of beer on the wall.\n",n,n,n-1);
        else if (n==2) 
            sprintf(v,"%d bottles of beer on the wall, %d bottles of beer.\n"
        "Take one down and pass it around, %d bottle of beer on the wall.\n",n,n,n-1);
        else if (n==1) 
            sprintf(v,"%d bottle of beer on the wall, %d bottle of beer.\n"
        "Take it down and pass it around, no more bottles of beer on the wall.\n",n,n);
        else 
            sprintf(v,"No more bottles of beer on the wall, no more bottles of beer.\n"
        "Go to the store and buy some more, 99 bottles of beer on the wall.\n");
        return v;
    }
    string sing(int b, int e) {
        string s="";
        for (int i = b; i>=e; i--) {
            s+=verse(i);
            if (i>e) s+="\n";
        }
        return s;
    }
    string sing(int b) {
        string s="";
        for (int i = b; i>=0; i--) {
            s+=verse(i);
            if (i>0) s+="\n";
        }
        return s;
    }
}  // namespace beer_song
