#if !defined(GRADE_SCHOOL_H)
#define GRADE_SCHOOL_H
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

namespace grade_school {
    class school {
        private:
            map<int, vector<string>> croster;

        public:
            school():croster({}) {};
            map<int, vector<string>> roster() const{
                map<int, vector<string>> sroster;
                for (auto &i : croster) {
                    vector<string> std = i.second;
                    sort(std.begin(), std.end());
                    sroster[i.first] = std;
                }
                return sroster;
            }
            void add(string name, int grade) {
                croster[grade].push_back(name);
            }
            vector<string> grade (int grd) const{
                for (auto &i : croster) {
                    if (i.first == grd) {
                        vector<string> std = i.second;
                        sort(std.begin(), std.end());
                        return std;
                    }
                }
                return {};
            }
    };
}  // namespace grade_school

#endif // GRADE_SCHOOL_H