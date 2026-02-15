#include "secret_handshake.h"
using namespace std;
namespace secret_handshake {
    vector<string> commands (int cmd){
        vector<string> ret={};    
        if ((cmd & 1)!=0) ret.push_back("wink");
        if ((cmd & 2)!=0) ret.push_back("double blink");
        if ((cmd & 4)!=0) ret.push_back("close your eyes");
        if ((cmd & 8)!=0) ret.push_back("jump");
        if ((cmd & 16)!=0) {
            vector<string> revret={};
            if (ret.size()==0) return revret;
            for (size_t i=ret.size()-1;;i--) {
                revret.push_back(ret[i]);
                if (i==0) return revret;
            }
        }
        return ret;
        
    }
}  // namespace secret_handshake
