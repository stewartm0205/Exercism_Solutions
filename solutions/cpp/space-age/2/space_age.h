#if !defined(SPACE_AGE_H)
#define SPACE_AGE_H

namespace space_age {
    const int EARTH_YEAR=31557600;
class space_age {
        private:
            const unsigned long long AGE_IN_SECS;
        public:
        space_age(const unsigned long long &seconds) : AGE_IN_SECS(seconds) {};
        float on_earth() const {return (float)AGE_IN_SECS/(float)EARTH_YEAR;};
        float on_mercury() const {return on_earth()/0.2408467;};
        float on_venus() const {return on_earth()/0.61519726;};
        float on_mars() const {return on_earth()/1.8808158;};
        float on_jupiter() const {return on_earth()/11.862615;};
        float on_saturn() const {return on_earth()/29.447498;};
        float on_uranus() const {return on_earth()/84.016846;};
        float on_neptune() const {return on_earth()/164.79132;};
        unsigned long long seconds() const { return AGE_IN_SECS;}
    };

}  // namespace space_age

#endif // SPACE_AGE_H