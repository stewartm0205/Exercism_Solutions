
pub fn reply(message: &str) -> &str {
    let msg: String = message.trim().to_string();

    if msg == "" {
        return "Fine. Be that way!";
    }
    let l: usize = msg.len() - 1;
    if msg == msg.to_uppercase() &&
        msg.chars().any(char::is_alphabetic) &&
        &msg[l..]=="?"
    {
        return "Calm down, I know what I'm doing!";
    }
    if &msg[l..]=="?"  {
        return "Sure.";
    }
   
    if msg == msg.to_uppercase() &&
        msg.chars().any(char::is_alphabetic) {
        return "Whoa, chill out!";
    }
    return "Whatever.";
}
