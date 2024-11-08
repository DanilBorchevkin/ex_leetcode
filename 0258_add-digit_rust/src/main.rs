
pub fn add_digits(num: i32) -> i32 {
    if num == 0 {
        return 0;
    }

    if num < 10 {
        return num;
    }

    let mut mut_num = num;
    let mut numbers: Vec<i32> = vec![];

    while num > 0 {
        numbers.insert(0, mut_num % 10);
        mut_num = mut_num / 10;
    }

    

    return num;
}


fn main() {
    println!("Hello, world!");
}

#[test]
fn test_basic(){
    assert_eq!(add_digits(0), 0); 
    assert_eq!(add_digits(5), 5);
}

#[test]
fn test_two_digit_one_step() {
    assert_eq!(add_digits(10), 1);
    assert_eq!(add_digits(26), 8); 
}