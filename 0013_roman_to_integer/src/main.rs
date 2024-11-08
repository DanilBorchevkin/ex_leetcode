
pub fn roman_to_int(s: String) -> i32 {
    let mut result : i32 = 0;

    let char_vec: Vec<char> = s.chars().collect();
    let mut prev_roman : char = '\0';
    for roman in char_vec {
        match roman {
            'I' => result += 1,

            'V' => {
                if prev_roman == 'I' { result -= 1 * 2}
                result += 5
            },

            'X' => {
                if prev_roman == 'I' { result -= 1 * 2}
                result += 10
            },

            'L' => {
                if prev_roman == 'X' { result -= 10 * 2}
                result += 50 
            },

            'C' => {
                if prev_roman == 'X' { result -= 10 * 2}
                result += 100
            },

            'D' => {
                if prev_roman == 'C' { result -= 100 * 2}
                result += 500
            },

            'M' => {
                if prev_roman == 'C' { result -= 100 * 2}
                result += 1000
            },
            _ => (),
        }
        prev_roman = roman;
    }

    result
}


fn main() {
    println!("Hello, world!");
}

#[test]
fn test_singles() {
    assert_eq!(roman_to_int("I".to_string()), 1);
    assert_eq!(roman_to_int("V".to_string()), 5);
    assert_eq!(roman_to_int("X".to_string()), 10);
    assert_eq!(roman_to_int("L".to_string()), 50);
    assert_eq!(roman_to_int("C".to_string()), 100);
    assert_eq!(roman_to_int("D".to_string()), 500);
    assert_eq!(roman_to_int("M".to_string()), 1000);
}

#[test]
fn test_only_ones() {
    assert_eq!(roman_to_int("I".to_string()), 1);
    assert_eq!(roman_to_int("II".to_string()), 2);
    assert_eq!(roman_to_int("III".to_string()), 3);
}

#[test]
fn test_58() {
    assert_eq!(roman_to_int("LVIII".to_string()), 58);
}

#[test]
fn test_1994() {
    assert_eq!(roman_to_int("MCMXCIV".to_string()), 1994);
}

#[test]
fn test_4() {
    assert_eq!(roman_to_int("IV".to_string()), 4);
}

#[test]
fn test_9() {
    assert_eq!(roman_to_int("IX".to_string()), 9);
}

#[test]
fn test_40() {
    assert_eq!(roman_to_int("XL".to_string()), 40);
}

#[test]
fn test_90() {
    assert_eq!(roman_to_int("XC".to_string()), 90);
}

#[test]
fn test_400() {
    assert_eq!(roman_to_int("CD".to_string()), 400);
}

#[test]
fn test_900() {
    assert_eq!(roman_to_int("CM".to_string()), 900);
}