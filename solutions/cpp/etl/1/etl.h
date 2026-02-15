#if !defined(ETL_H)
#define ETL_H
#include <map>
#include <vector>
#include <iostream>
using namespace std;
namespace etl {
    map<char, int> transform(map<int, std::vector<char>> old);
}  // namespace etl

#endif // ETL_H