pub fn plus_one(digits: Vec<i32>) -> Vec<i32> {
    let mut result : Vec<i32> = digits;

    let mut is_carrying = false;
    for idx in (0..result.len()).rev() {
        if (result[idx] + 1) >= 10 {
            result[idx] = 0;
            is_carrying = true;
        } else {
            is_carrying = false;
            result[idx] += 1;
            break;
        }
    }

    if is_carrying == true {
        let mut add_digit : Vec<i32> = vec![1,];
        add_digit.extend(result);
        result = add_digit;
    }

    result
}

fn main() {
    println!("Hello, world!");
}

#[test]
fn test_basic() {
    assert_eq!(plus_one(vec![0]), vec![1]);
}

#[test]
fn test_four() {
    assert_eq!(plus_one(vec![0, 0, 0, 1]), vec![0, 0, 0, 2]);
}

#[test]
fn test_simple_one_carry() {
    assert_eq!(plus_one(vec![0, 0, 0, 9]), vec![0, 0, 1, 0]);
}

#[test]
fn test_simple_two_carry() {
    assert_eq!(plus_one(vec![0, 0, 9, 9]), vec![0, 1, 0, 0]);
}

#[test]
fn test_simple_add_digit() {
    assert_eq!(plus_one(vec![9]), vec![1, 0]);
}