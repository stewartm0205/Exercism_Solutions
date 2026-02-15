#if !defined(CLOCK_H)
#define CLOCK_H
#include <string>
#include <iostream>
using namespace std;
namespace date_independent {
class clock {
    private:
        int hour;
        int minute;
    public:
        clock (int h, int m): hour(h), minute(m) {
            if (minute<0) {
                hour = (hour-1) + minute / 60;
                minute = 60 + (minute % 60);               
            } else {
                hour = hour + (minute / 60);
                minute = minute % 60;
            }
            hour = hour % 24; 
            if (hour < 0) hour = 24 + hour;
        }
        static clock at (int h, int m) {
            return clock(h, m);
        }
        clock plus (int m_in) {
            int m = minute + m_in;
            return clock(hour, m);
        }
        operator string() const{
            string h = to_string(hour);
            if (h.length()<2) h="0" + h;
            string m = to_string(minute);
            if (m.length()<2) m="0" + m;
            return h+":"+m;
        }
        bool operator== (clock c) const{
            if (hour !=c.hour || minute != c.minute) return false;
            else return true;
        }
        bool operator!= (clock c) const{
            if (hour ==c.hour && minute == c.minute) return false;
            else return true;
        }
};
}  // namespace date_independent

#endif // CLOCK_H