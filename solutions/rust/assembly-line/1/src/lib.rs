// This stub file contains items which aren't used yet; feel free to remove this module attribute
// to enable stricter warnings.
#![allow(unused)]

pub fn production_rate_per_hour(speed: u8) -> f64 {
    match speed{
        1|2|3|4=>return (speed as f64)*221.0,
        5|6|7|8=>return (speed as f64)*221.0 * 0.9,
        9|10=>return (speed as f64)*221.0 * 0.77,
        _=>return 0.0,
    }
}

pub fn working_items_per_minute(speed: u8) -> u32 {
    return (production_rate_per_hour(speed)/60.0) as u32;
}
