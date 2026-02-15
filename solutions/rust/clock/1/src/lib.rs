
use std::time::Duration;
#[derive(Debug)]
pub struct Clock {
 d:Duration,
}

impl Clock {
    pub fn new(hours: i32, minutes: i32) -> Self {
        let mut c:Clock = Clock {d:Duration::from_secs(0)};
        c.d = Duration::from_secs(0);
        c.d = Duration::from_secs((60*60*hours+60*minutes).try_into().unwrap());
        return c;
        //unimplemented!(
        //    "Construct a new Clock from {} hours and {} minutes",
       //     hours,
       //     minutes
      //);
    }

    pub fn add_minutes(&self, minutes: i32) -> Self {
        let mut c:Clock = Clock {d:Duration::from_secs(0)};
        c.d = self.d;
        c.d = c.d + Duration::from_secs((60*minutes).try_into().unwrap());
        return c;
       // unimplemented!("Add {} minutes to existing Clock time", minutes);
    }
}
