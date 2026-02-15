#include "gigasecond.h"

namespace gigasecond {
    ptime advance(ptime ctime) {
        return ctime+= seconds(GIGASECS);
    }
}  // namespace gigasecond
