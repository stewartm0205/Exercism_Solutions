#if !defined(MEETUP_H)
#define MEETUP_H
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/lexical_cast.hpp>
#include <string>
#include <iostream>

using namespace std;
namespace meetup {
    class scheduler {
        private:
            int yy;
            int mm;  
        public:
            scheduler(int mm_in, int yy_in): yy(yy_in), mm(mm_in) {};
            boost::gregorian::date monteenth() const {
                return teenth(boost::gregorian::Monday);
            }
            boost::gregorian::date tuesteenth() const {
                return teenth(boost::gregorian::Tuesday);
            }
            boost::gregorian::date wednesteenth() const {
                return teenth(boost::gregorian::Wednesday);
            }
            boost::gregorian::date thursteenth() const {
                return teenth(boost::gregorian::Thursday);
            }
            boost::gregorian::date friteenth() const {
                return teenth(boost::gregorian::Friday);
            }
            boost::gregorian::date saturteenth() const {
                return teenth(boost::gregorian::Saturday);
            }
            boost::gregorian::date sunteenth() const {
                return teenth(boost::gregorian::Sunday);
            }
            boost::gregorian::date teenth(int day_of_week_in) const {
                auto greg_year = yy;
                auto greg_month = mm;
                boost::gregorian::date day;
                for (int dow=13;dow<=19;dow++) {
                    day = boost::gregorian::date(greg_year, greg_month, dow);
                    if (day.day_of_week()==day_of_week_in) return day;
                }
                return day;
            }
            boost::gregorian::date first_monday() const {
                return ord_dow(1, boost::gregorian::Monday);
            }
            boost::gregorian::date first_tuesday() const {
                return ord_dow(1, boost::gregorian::Tuesday);
            }        
            boost::gregorian::date first_wednesday() const {
                return ord_dow(1, boost::gregorian::Wednesday);
            }            
            boost::gregorian::date first_thursday() const {
                return ord_dow(1, boost::gregorian::Thursday);
            }            
            boost::gregorian::date first_friday() const {
                return ord_dow(1, boost::gregorian::Friday);
            }            
            boost::gregorian::date first_saturday() const {
                return ord_dow(1, boost::gregorian::Saturday);
            }
            boost::gregorian::date first_sunday() const {
                return ord_dow(1, boost::gregorian::Sunday);
            }
            boost::gregorian::date second_monday() const {
                return ord_dow(2, boost::gregorian::Monday);
            }
            boost::gregorian::date second_tuesday() const {
                return ord_dow(2, boost::gregorian::Tuesday);
            }        
            boost::gregorian::date second_wednesday() const {
                return ord_dow(2, boost::gregorian::Wednesday);
            }            
            boost::gregorian::date second_thursday() const {
                return ord_dow(2, boost::gregorian::Thursday);
            }            
            boost::gregorian::date second_friday() const {
                return ord_dow(2, boost::gregorian::Friday);
            }            
            boost::gregorian::date second_saturday() const {
                return ord_dow(2, boost::gregorian::Saturday);
            }
            boost::gregorian::date second_sunday() const {
                return ord_dow(2, boost::gregorian::Sunday);
            }
            boost::gregorian::date third_monday() const {
                return ord_dow(3, boost::gregorian::Monday);
            }
            boost::gregorian::date third_tuesday() const {
                return ord_dow(3, boost::gregorian::Tuesday);
            }        
            boost::gregorian::date third_wednesday() const {
                return ord_dow(3, boost::gregorian::Wednesday);
            }            
            boost::gregorian::date third_thursday() const {
                return ord_dow(3, boost::gregorian::Thursday);
            }            
            boost::gregorian::date third_friday() const {
                return ord_dow(3, boost::gregorian::Friday);
            }            
            boost::gregorian::date third_saturday() const {
                return ord_dow(3, boost::gregorian::Saturday);
            }
            boost::gregorian::date third_sunday() const {
                return ord_dow(3, boost::gregorian::Sunday);
            }
            boost::gregorian::date fourth_monday() const {
                return ord_dow(4, boost::gregorian::Monday);
            }
            boost::gregorian::date fourth_tuesday() const {
                return ord_dow(4, boost::gregorian::Tuesday);
            }        
            boost::gregorian::date fourth_wednesday() const {
                return ord_dow(4, boost::gregorian::Wednesday);
            }            
            boost::gregorian::date fourth_thursday() const {
                return ord_dow(4, boost::gregorian::Thursday);
            }            
            boost::gregorian::date fourth_friday() const {
                return ord_dow(4, boost::gregorian::Friday);
            }            
            boost::gregorian::date fourth_saturday() const {
                return ord_dow(4, boost::gregorian::Saturday);
            }
            boost::gregorian::date fourth_sunday() const {
                return ord_dow(4, boost::gregorian::Sunday);
            }
            boost::gregorian::date ord_dow(int order, int day_of_week_in) const {
                auto greg_year = yy;
                auto greg_month = mm;
                boost::gregorian::date day;
                for (int dow=7*(order-1)+1;dow<=7*order;dow++) {
                    day = boost::gregorian::date(greg_year, greg_month, dow);
                    if (day.day_of_week()==day_of_week_in) return day;
                }
                return day;
            }
            boost::gregorian::date last_monday() const {
                return last_dow(boost::gregorian::Monday);
            }
            boost::gregorian::date last_tuesday() const {
                return last_dow(boost::gregorian::Tuesday);
            }        
            boost::gregorian::date last_wednesday() const {
                return last_dow(boost::gregorian::Wednesday);
            }            
            boost::gregorian::date last_thursday() const {
                return last_dow(boost::gregorian::Thursday);
            }            
            boost::gregorian::date last_friday() const {
                return last_dow(boost::gregorian::Friday);
            }            
            boost::gregorian::date last_saturday() const {
                return last_dow(boost::gregorian::Saturday);
            }
            boost::gregorian::date last_sunday() const {
                return last_dow(boost::gregorian::Sunday);
            }
            boost::gregorian::date last_dow(int day_of_week_in) const {
                auto greg_year = yy;
                auto greg_month = mm;
                int last_day_of_month;
                if (mm==2) last_day_of_month=28;
                else if (mm==4 || mm==6 || mm==9 || mm==11) last_day_of_month=30;
                else last_day_of_month=31;
                boost::gregorian::date day;
                for (int dow=last_day_of_month;dow>=21;dow--) {
                    day = boost::gregorian::date(greg_year, greg_month, dow);
                    if (day.day_of_week()==day_of_week_in) return day;
                }
                return day;
            }

    };
}  // namespace meetup

#endif // MEETUP_H