#include "clock.h"
clock_t clock_create(int hour, int minute){
    clock_t c;
  
    if (minute<0) {
        hour = hour - 1 + minute/60;
        minute=60+minute%60;
    }    
    if (minute>=60) {
        hour=hour + minute/60;
        minute=minute%60;
    }
    if (hour>=24) hour=hour%24; 
    if (hour<=-24) hour=hour%24;
    if (hour<0) hour=24+hour;

    sprintf(c.text,"%02d:%02d",hour,minute);
    return c;
}
clock_t clock_add(clock_t clock, int minute_add){
    clock_t c;
    int h=(clock.text[0]-'0')*10+clock.text[1]-'0';
    int m=(clock.text[3]-'0')*10+clock.text[4]-'0';
    m=m+minute_add;
    if (m>59){
        h=h+m/60;
        m=m%60;
    }
    if (h>=24) h=h%24;
    sprintf(c.text,"%02d:%02d",h,m);
    return c;
}
clock_t clock_subtract(clock_t clock, int minute_subtract){
    clock_t c;
    int h=(clock.text[0]-'0')*10+clock.text[1]-'0';
    int m=(clock.text[3]-'0')*10+clock.text[4]-'0';
    m=m-minute_subtract;
    if (m<0) {
        h=h-1+m/60;
        h=h%24;
        if (h<0) h=24+h%24;
        m=60+m%60;
    }
    if (m==60) m=0;
    sprintf(c.text,"%02d:%02d",h,m);
    return c;
}
bool clock_is_equal(clock_t a, clock_t b){
    if (strcmp(a.text,b.text)){
        return false;
    } else {
        return true;
    }
}