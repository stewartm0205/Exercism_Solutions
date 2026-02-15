#include "gigasecond.h"
#include "ctype.h"
#include "stdio.h"
#include "time.h"

time_t gigasecond_after(time_t bdate)
{
	return bdate + 1000000000;
}
