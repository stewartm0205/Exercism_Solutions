#if !defined(ALLERGIES_H)
#define ALLERGIES_H
#include <string>
#include <map>
#include <vector>
#include <unordered_set>
#include <iostream>


using namespace std;

namespace allergies {
    class allergy_test {
        private:
            int all_all;
            map<string, int> allmap = {{"eggs", 1}, {"peanuts", 2},
                                        {"shellfish", 4}, {"strawberries", 8},
                                        {"tomatoes", 16}, {"chocolate", 32},
                                        {"pollen", 64},{"cats",128}};

        public:
            allergy_test(int all):all_all(all) {};
            bool is_allergic_to (string substance){
                if (all_all & allmap[substance]) return true;
                else return false;
            }
            unordered_set <string> get_allergies() const{
                unordered_set<string> als={};
                for (auto &al : allmap) {
                    if (al.second & all_all) {
                        als.insert(al.first);
                    }
                }
                return als;
            }
    };   
}  // namespace allergies

#endif // ALLERGIES_H