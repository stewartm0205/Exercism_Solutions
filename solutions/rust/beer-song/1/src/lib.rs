pub fn verse(n: u32) -> String {
    if n > 1 {
        return n.to_string().to_owned() + &" bottles of beer on the wall, ".to_string() +
               &n.to_string() + &" bottles of beer.\n".to_string() +
            &"Take one down and pass it around, ".to_string() + &(n-1).to_string() +
            &" bottles of beer on the wall.\n".to_string();
    } else if n==1 {
        return "1 bottle of beer on the wall, 1 bottle of beer.\nTake it down and pass it around, no more bottles of beer on the wall.\n".to_string();
    } else {
        return "No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy some more, 99 bottles of beer on the wall.\n".to_string();
    }
}

pub fn sing(start: u32, end: u32) -> String {
    let mut vs: String = "".to_string();
    let mut vi = start;
    println!("Sing ======> start={},end={}",start,end);
    loop {
        println!("vi={}",vi);
        vs = vs + &verse(vi).to_owned()+&"\n".to_string();
        if vi == 0 { break;}
        if start > end {
             vi = vi - 1;
        } else {
            vi = vi + 1;
        }
    }
    return vs;
}
