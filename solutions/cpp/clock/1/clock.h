#if !defined(CLOCK_H)
#define CLOCK_H
using namespace std;
namespace date_independent {
class clock {
    struct hm {
    int hour;
    int minute;
    } curhm;
    clock (int h, int m) {
        at(h,m);
    }
    struct hm at(int h, int m) {
        struct hm curhm;
        curhm.minute = m % 60;
        curhm.hour = (h + m/60) % 24;
        return curhm;
    }
    struct hm plus (int m){
        struct hm thm;
        thm.minute = (curhm.minute+m)% 60;
        thm.hour = (curhm.hour + (curhm.minute+m)/60) % 24;
        curhm=thm;
        return curhm;
    }
};
}  // namespace date_independent

#endif // CLOCK_H