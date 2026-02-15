#if !defined(GIGASECOND_H)
#define GIGASECOND_H
#define GIGASECS 1000000000
#include "boost/date_time/posix_time/posix_time.hpp"
using namespace boost::posix_time;
namespace gigasecond {
    ptime advance(ptime ctime);
}  // namespace gigasecond

#endif // GIGASECOND_H