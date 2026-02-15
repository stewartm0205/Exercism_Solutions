#if !defined(ROBOT_NAME_H)
#define ROBOT_NAME_H
#include <string>
#include <vector>
#include <iostream>
#include <algorithm> 
using namespace std;
namespace robot_name {
    class robot {
        private:
            string rname;

        public:
            static vector<string> names;
            robot() {
                gen_name();
            }
            void gen_name () {
                string alpha="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
                string zeroes="000";
                while (true){
                    rname=alpha.substr(rand()%26,1)+
                        alpha.substr(rand()%26,1);
                    string t =to_string(rand()%1000);
                    t=zeroes.substr(1,3-t.length())+t;
                    rname+=t;
                    if (!count(names.begin(), names.end(),rname)) break;
                }
                names.push_back(rname);
            }
            string name() const {
                return rname;
            }
            void reset() {
                gen_name();
            }
    };
    

}  // namespace robot_name

#endif // ROBOT_NAME_H