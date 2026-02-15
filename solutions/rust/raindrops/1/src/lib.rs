

pub fn raindrops(n: u32) -> String {
    let mut res: String = String::from("");
    if n % 3 == 0 {
        res += "Pling";
    }
    if n % 5 == 0  {
        res += "Plang";
    }
    if n % 7 == 0  {
        res += "Plong";
    }
    if n % 3 != 0 && n % 5 != 0 && n % 7 !=0 {
        res = n.to_string();
    }
    return res;
}
