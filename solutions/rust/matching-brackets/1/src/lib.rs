pub fn brackets_are_balanced(string: &str) -> bool {
    let mut stack: [char; 256] = [' '; 256];
    let mut si: usize = 0;

    for s in string.chars() {
        match s {
            ']' => if si >0 && stack[si] == '[' {
                        si = si - 1;
                    } else {
                        si = si + 1;
                        stack[si] = s;
                    },
            '}' => if si >0 && stack[si]  == '{' {
                        si = si - 1;
                    } else {
                        si = si + 1;
                        stack[si] = s;
                    },
            ')' => if si >0 && stack[si]  == '(' {
                        si = si - 1;
                    } else {
                        si = si + 1;
                        stack[si] = s;
                    },
            '['|'{'|'(' =>  {si = si + 1;
                            stack[si] = s;},
            _ => (),
        }
    }
    if si  > 0 {
        return false;
    } else {
        return true;
    }
}
