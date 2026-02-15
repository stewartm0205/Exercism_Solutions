#include "food_chain.h"
using namespace std;
namespace food_chain {
    string verse(int n) {
        vector<string> animals={"fly","spider","bird","cat","dog","goat",
                       "cow", "horse"};
        string verse="";
        for (int v=n;v>=1;v--) {      
            if (v==n) verse += "I know an old lady who swallowed a " + animals[v-1] + ".\n";
            if (n==2 && animals[v-1]=="spider") verse+="It wriggled and jiggled and tickled inside her.\n";
            if (n==3 && animals[v-1]=="bird") verse += "How absurd to swallow a bird!\n";
            if (n==4 && animals[v-1]=="cat") verse += "Imagine that, to swallow a cat!\n";
            if (n==5 && animals[v-1]=="dog") verse += "What a hog, to swallow a dog!\n";
            if (n==6 && animals[v-1]=="goat") verse += "Just opened her throat and swallowed a goat!\n";
            if (n==7 && animals[v-1]=="cow") verse += "I don't know how she swallowed a cow!\n";
            if (n==8 && animals[v-1]=="horse") {
                verse += "She's dead, of course!\n";
                break;
            }    
            if (animals[v-1]=="bird") verse += "She swallowed the "+ animals[v-1] + 
            " to catch the " + animals[v-2] +" that wriggled and jiggled and tickled inside her.\n";
            if (v>=2 && animals[v-1]!="bird") verse += "She swallowed the "+ animals[v-1] + 
            " to catch the " + animals[v-2] +".\n";
            if (v==1) verse += "I don't know why she swallowed the fly. Perhaps she'll die.\n";
        }         
        return verse;     
    }
    string verses(int s, int e) {
        string vs="";
        for (int v=s; v<=e; v++) {
            vs+=verse(v);
            vs+="\n";
        }
        return vs;
    }
    string sing() {
        return verses(1,8);
    }
}  // namespace food_chain

/*"I know an old lady who swallowed a fly.
"I don't know why she swallowed the fly. Perhaps she'll die.

"I know an old lady who swallowed a spider.
"It wriggled and jiggled and tickled inside her.
"She swallowed the spider to catch the fly.
"I don't know why she swallowed the fly. Perhaps she'll die.

I know an old lady who swallowed a bird.
How absurd to swallow a bird!
She swallowed the bird to catch the spider that wriggled and jiggled and tickled inside her.
She swallowed the spider to catch the fly.
I don't know why she swallowed the fly. Perhaps she'll die.

I know an old lady who swallowed a cat.
Imagine that, to swallow a cat!
She swallowed the cat to catch the bird.
She swallowed the bird to catch the spider that wriggled and jiggled and tickled inside her.
She swallowed the spider to catch the fly.
I don't know why she swallowed the fly. Perhaps she'll die.

I know an old lady who swallowed a dog.
What a hog, to swallow a dog!
She swallowed the dog to catch the cat.
She swallowed the cat to catch the bird.
She swallowed the bird to catch the spider that wriggled and jiggled and tickled inside her.
She swallowed the spider to catch the fly.
I don't know why she swallowed the fly. Perhaps she'll die.

I know an old lady who swallowed a goat.
Just opened her throat and swallowed a goat!
She swallowed the goat to catch the dog.
She swallowed the dog to catch the cat.
She swallowed the cat to catch the bird.
She swallowed the bird to catch the spider that wriggled and jiggled and tickled inside her.
She swallowed the spider to catch the fly.
I don't know why she swallowed the fly. Perhaps she'll die.

I know an old lady who swallowed a cow.
I don't know how she swallowed a cow!
She swallowed the cow to catch the goat.
She swallowed the goat to catch the dog.
She swallowed the dog to catch the cat.
She swallowed the cat to catch the bird.
She swallowed the bird to catch the spider that wriggled and jiggled and tickled inside her.
She swallowed the spider to catch the fly.
I don't know why she swallowed the fly. Perhaps she'll die.

I know an old lady who swallowed a horse.
She's dead, of course!
*/