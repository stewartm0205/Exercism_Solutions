#include "meetup.h"
#include <time.h>
#include <stdio.h>
#include <string.h>

int meetup_day_of_month(unsigned int year, unsigned int month, const char *week,
                        const char *day_of_week){ 
    char * days[] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    int dow = 0;
    for (int i=0; i<7; i++) {
        if (!strcmp(day_of_week,days[i])){
            dow=i;
            break;
        }
    }
   
    struct tm d ={.tm_sec = 0, .tm_min=0, .tm_hour=0, .tm_mon=month-1, 
                  .tm_year=year-1900};
    
    int w=0;
    int last =0;
    int dom;
    int ldm = 31;
    if (month==2 && year%4==0) ldm = 29;
    if (month==2 && year%4!=0) ldm = 28;
    if (month==4||month==6||month==9||month==11) ldm = 30;
    for (dom = 1; dom <= ldm; dom++) {
        d.tm_mday=dom;
        mktime(&d);
        // check 
    
        if (d.tm_wday == dow) {
            if (dom>=13 && dom<= 19&& !strcmp("teenth",week)) return dom;
            w++;
            if (w==1 && !strcmp("first",week)) return dom;
            if (w==2 && !strcmp("second",week)) return dom;
            if (w==3 && !strcmp("third",week)) return dom;
            if (w==4 && !strcmp("fourth",week)) return dom;
            last=dom;
        }
    }
    if (last != 0) return last;
    return dom;
}
