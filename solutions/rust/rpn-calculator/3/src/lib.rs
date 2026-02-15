

#[derive(Debug)]
pub enum CalculatorInput {
    Add,
    Subtract,
    Multiply,
    Divide,
    Value(i32),
}

pub fn evaluate(inputs: &[CalculatorInput]) -> Option<i32> {
    let mut s = Vec::<i32>::new();
    for ci in inputs {
        match *ci {
            CalculatorInput::Add => {if s.len() <= 1 { return None};
                    let a: i32 = s.pop().unwrap() as i32;
                    let b: i32 = s.pop().unwrap() as i32;
                    let c: i32 = b+a;
                     s.push(c);},
            CalculatorInput::Subtract =>{if s.len() <= 1 { return None};
                           let a = s.pop().unwrap();
                           let b = s.pop().unwrap();
                            s.push(b-a);},
            CalculatorInput::Multiply =>{ if s.len() <= 1 { return None};
                         let   a = s.pop().unwrap();
                         let b = s.pop().unwrap();
                         s.push(b*a);},
            CalculatorInput::Divide =>{ if s.len() <= 1 { return None};
                        let a = s.pop().unwrap();
                        let b = s.pop().unwrap();
                        s.push(b/a);},
            CalculatorInput::Value(number)=> {
                s.push(number);},
        }
    }
    if s.len()==1 {
        return s.pop();
    } else {
        return None;
    }
}
