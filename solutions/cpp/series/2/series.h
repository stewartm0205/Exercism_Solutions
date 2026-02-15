#if !defined(SERIES_H)
#define SERIES_H
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;
namespace series {
    vector<int> digits(string d);
    vector<vector<int>> slice(string d, int size);
}  // namespace series

#endif // SERIES_H