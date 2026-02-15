#if !defined(ALLERGIES_H)
#define ALLERGIES_H
#include <string>
#include <map>
#include <vector>


using namespace std;

namespace allergies {
    class score {
        private:
            int all_all;
            map<string, int> allmap = {{"eggs", 1}, {"peanuts", 2},
                                        {"shellfish", 4}, {"strawberries", 8},
                                        {"tomatoes", 16}, {"chocolate", 32},
                                        {"pollen", 64},{"cats",28}};

        public:
            allergy_test(int t) : all_all{t}{};
            bool is_allergic_to (string substance){
                if (all_all && allmap[substance]) return true;
                else return false;
            }
            vector<string> get_allergies(){
                vector<string> als;
                for (auto &al : allmap) {
                    if (al.second & all_all) {
                        als.push_back(al.first);
                    }
                }
                return als;
            }
    };   
}  // namespace allergies

#endif // ALLERGIES_H