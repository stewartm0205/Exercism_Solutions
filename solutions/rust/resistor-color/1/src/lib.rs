
//use int_enum::IntEnum;

use enum_iterator::IntoEnumIterator;

#[derive(Clone, IntoEnumIterator, PartialEq, Debug)]
pub enum ResistorColor {
    Black,
    Brown,
    Red,
    Orange,
    Yellow,
    Green,
    Blue,
    Violet,
    Grey,
    White,
}

pub fn color_to_value(_color: ResistorColor) -> usize {
    match _color {
        ResistorColor::Black => return 0,
        ResistorColor::Brown => return 1,
        ResistorColor::Red => return 2,
        ResistorColor::Orange => return 3,
        ResistorColor::Yellow => return 4,
        ResistorColor::Green => return 5,
        ResistorColor::Blue => return 6,
        ResistorColor::Violet => return 7,
        ResistorColor::Grey => return 8,
        ResistorColor::White => return 9,

    }
}

pub fn value_to_color_string(value: usize) -> String {

    match value {
        0 => return "Black".to_string(),
        1 => return "Brown".to_string(),
        2 => return "Red".to_string(),
        3 => return "Orange".to_string(),
        4 => return "Yellow".to_string(),
        5 => return "Green".to_string(),
        6 => return "Blue".to_string(),
        7 => return "Violet".to_string(),
        8 => return "Grey".to_string(),
        9 => return "White".to_string(),
        _ => return "value out of range".to_string(),
    }
}


pub fn colors() -> Vec<ResistorColor> {
    let mut rcvec = Vec::<ResistorColor>::new();
    for rc in ResistorColor::into_enum_iter() {
		rcvec.push(rc)
	}
    return rcvec;

}
