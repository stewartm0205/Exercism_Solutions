use std::fmt::{Display, Formatter, Result};

pub struct Roman {
    value: String,
}

impl Display for Roman {
    fn fmt(&self, _f: &mut Formatter<'_>) -> Result {
        return Formatter::write_str(_f,&self.value);
    }
}

impl From<u32> for Roman {
    fn from(num: u32) -> Self {
        let mut tn: u32 = num;
        let mut rn: String ="".to_string();
        while tn>0 {
            match tn {
               1000..=9999 =>{rn = rn+&"M".to_string();
               tn = tn - 1000},
               900..=999 =>{rn = rn+&"CM".to_string();
               tn = tn - 900},
               500..=899 =>{rn = rn+&"D".to_string();
               tn = tn - 500},
               400..=499 =>{rn = rn+&"CD".to_string();
               tn = tn - 400},
               100..=399 =>{rn = rn+&"C".to_string();
               tn = tn - 100},
               90..=99 =>{rn = rn+&"XC".to_string();
               tn = tn - 90},
               50..=89 =>{rn = rn+&"L".to_string();
               tn = tn - 50},
               40..=49 =>{rn = rn+&"XL".to_string();
               tn = tn - 40},
               10..=39 =>{rn = rn+&"X".to_string();
               tn = tn - 10},
               9 =>{rn = rn+&"IX".to_string();
               tn = tn - 9},
               5..=8 =>{rn = rn+&"V".to_string();
               tn = tn - 5},
               4 =>{rn = rn+&"IV".to_string();
               tn = tn - 4},
               1..=3 =>{rn = rn+&"I".to_string();
               tn = tn - 1;},
               _ => ()
            }
        }
        return Roman{value:rn};

    }
}
