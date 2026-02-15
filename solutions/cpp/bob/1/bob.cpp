#include "bob.h"
using namespace std;
namespace bob {
    string hey(string phrase){
        if (!regex_search(phrase,regex("[a-z]+")) && regex_search(phrase,regex("[A-Z]+\\?"))) return "Calm down, I know what I'm doing!";
        if (regex_search(phrase,regex("^.*\\? *$"))) return "Sure.";
        if (!regex_search(phrase,regex("[a-z]+")) && regex_search(phrase,regex("[A-Z]+"))) return "Whoa, chill out!";
        if (regex_search(phrase,regex("^\\s*$"))) return "Fine. Be that way!";
        return "Whatever.";
        
    }
}  // namespace bob
