#include "pascals_triangle.h"
using namespace std;
namespace pascals_triangle {
    vector<vector<int>> generate_rows(int nrows){
        vector<vector<int>> pt;
        for (int i=0; i<nrows; i++){
            pt.push_back({});
            for (int j=0; j<=i; j++){
                if (j==0 || j==i) pt[i].push_back(1);
                else pt[i].push_back(pt[i-1][j-1]+pt[i-1][j]);
            }
        }
        return pt;
}
}  // namespace pascals_triangle
