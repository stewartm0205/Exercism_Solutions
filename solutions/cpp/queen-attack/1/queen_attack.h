#if !defined(QUEEN_ATTACK_H)
#define QUEEN_ATTACK_H
#include <string>
#include <utility>
#include <stdexcept>
using namespace std;

namespace queen_attack {
class chess_board{
    private:
        pair<int,int> white_pos;
        pair<int,int> black_pos;
    public:
    chess_board (): 
       white_pos(make_pair(0, 3)), black_pos(make_pair(7,3)) {};
    chess_board (pair<int, int> white, pair<int, int> black): 
       white_pos(white), black_pos(black) {
           if (white_pos==black_pos) throw domain_error("B & W: same square");
       };
    pair<int,int> white() const {
        return white_pos;
    }
    pair<int,int> black() const {
        return black_pos;
    }
    operator string () const {
        string ret="";
        int wy=white_pos.first;
        int wx=white_pos.second;

        int by=black_pos.first;
        int bx=black_pos.second;
        for(int r=0; r<8; r++){
            for (int c=0; c<8; c++) {
               if (r == wy && c == wx) ret+="W ";
               else if (r == by && c == bx) ret+="B ";
               else ret+="_ "; 
            }
            ret=ret.substr(0,ret.length()-1);
            ret+="\n";
        }
        return ret;
    }
    bool can_attack() const {

        int wy=white_pos.first;
        int wx=white_pos.second;

        int by=black_pos.first;
        int bx=black_pos.second; 

        if (wy == by || wx == bx) return true;
        if (abs(wx-bx) == abs(wy-by)) return true;
        return false;
    }
};
}  // namespace queen_attack

#endif // QUEEN_ATTACK_H