// The code below is a stub. Just enough to satisfy the compiler.
// In order to pass the tests you can add-to or change any of this code.

#[derive(Debug)]
pub struct Duration;

impl From<u64> for Duration {
    fn from(s: u64) -> Self {
        unimplemented!("s, measured in seconds: {}", s)
    }
}

pub trait Planet {
    fn years_during(d: &Duration) -> f64 {
        return d/(orbital_period * 31_557_600);
       // unimplemented!(
        //    "convert a duration ({:?}) to the number of years on this planet for that duration",
       //     d,
       // );
    }
}

pub struct Mercury {
    orbital_period: f64 = 0.2408467;
};
pub struct Venus;
pub struct Earth;
pub struct Mars;
pub struct Jupiter;
pub struct Saturn;
pub struct Uranus;
pub struct Neptune;

impl Planet for Mercury {
    fn years_during()
}
impl Planet for Venus {}
impl Planet for Earth {}
impl Planet for Mars {}
impl Planet for Jupiter {}
impl Planet for Saturn {}
impl Planet for Uranus {}
impl Planet for Neptune {}
