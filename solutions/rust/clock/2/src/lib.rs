use std::fmt;
#[derive(Debug, Eq, PartialEq)]
pub struct Clock {
 minutes: i32,
}

impl Clock {
    pub fn new(hours: i32, minutes: i32) -> Self {
        println!("hours={},minutes={}",hours,minutes);
        let mut m: i32 = hours * 60 + minutes;
        let mut h: i32 = (m / 60) % 24;
        m = m % 60;
        if m < 0 {
            m = 60 + m;
            h = h - 1;
        }
        if h < 0 { h = 24 + (h % 24);}

        println!("h={},m={}",h,m);
        return Clock {minutes: (h * 60 + m) % (24 * 60)};
    }

    pub fn add_minutes(&self, minutes: i32) -> Self {
        return Clock::new(0,self.minutes + minutes);
    }

}
impl fmt::Display for Clock{
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        return write!(f,"{:02}:{:02}", self.minutes / 60, self.minutes % 60);
    }
}
