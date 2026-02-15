#if !defined(ROBOT_SIMULATOR_H)
#define ROBOT_SIMULATOR_H
#include <utility>
#include <string>
using namespace std;

namespace robot_simulator {
    enum Bearing {NORTH,EAST,SOUTH,WEST};
    class Robot {
        private:
            pair<int, int> r_pos;
            Bearing r_bearing;
        public:
            Robot () {
                r_pos= {0,0};
                r_bearing = Bearing::NORTH;
            }
            Robot (pair<int, int> pos_in, Bearing b_in) {
                r_pos= pos_in;
                r_bearing = b_in;
            }
            pair<int, int> get_position () const {
                return r_pos;
            }
            Bearing get_bearing () const {
                return r_bearing;
            }
            void turn_right () {
                switch (r_bearing){
                    case NORTH: r_bearing=EAST; break;
                    case EAST: r_bearing=SOUTH; break;
                    case SOUTH: r_bearing=WEST; break;
                    case WEST: r_bearing=NORTH; break;  
                }
            }
            void turn_left () {
                switch (r_bearing){
                    case NORTH: r_bearing=WEST; break; 
                    case WEST: r_bearing=SOUTH; break; 
                    case SOUTH: r_bearing=EAST; break; 
                    case EAST: r_bearing=NORTH; break;   
                }
            }
            void advance () {
                switch (r_bearing){
                    case NORTH: r_pos.second++; break; 
                    case WEST: r_pos.first--; break; 
                    case SOUTH: r_pos.second--; break; 
                    case EAST: r_pos.first++; break;   
                }
            }
            void execute_sequence(string seq){
                for (auto ch : seq) {
                    switch(ch) {
                        case 'R': turn_right(); break;
                        case 'L': turn_left(); break;
                        case 'A': advance(); break;
                    }
                }
            }


    };
}  // namespace robot_simulator

#endif // ROBOT_SIMULATOR_H