#if !defined(SPACE_AGE_H)
#define SPACE_AGE_H

namespace space_age {
    const int EARTH_YEAR=31557600;
    struct space_age {
        float seconds;
        float on_earth() {return seconds/EARTH_YEAR;};
        float on_mercury() {return on_earth()/0.2408467;};
        float on_venus() {return on_earth()/0.61519726;};
        float on_mars() {return on_earth()/1.8808158;};
        float on_jupiter() {return on_earth()/11.862615;};
        float on_saturn() {return on_earth()/29.447498;};
        float on_uranus() {return on_earth()/84.016846;};
        float on_neptune() {return on_earth()/164.79132;};
    } age_t;


}  // namespace space_age

#endif // SPACE_AGE_H