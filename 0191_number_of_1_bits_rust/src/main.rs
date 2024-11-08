pub fn hamming_weight(n: i32) -> i32 {
    let mut result = 0;

    for shift in 0..32 {
        if (n & (1 << shift)) == (1 << shift) {
            result += 1;
        }
    }

    return result;
}

fn main() {
    println!("Hello, world!");
}

#[test]
fn test_simple_case() {
    assert_eq!(0, hamming_weight(0));
}

#[test]
fn test_pow_2() {
    assert_eq!(1, hamming_weight(1));
    assert_eq!(1, hamming_weight(2));
    assert_eq!(1, hamming_weight(4));
    assert_eq!(1, hamming_weight(8));
    assert_eq!(1, hamming_weight(16));
}

#[test]
fn test_twos() {
    assert_eq!(2, hamming_weight(0x11));
    assert_eq!(2, hamming_weight(0x22));
    assert_eq!(2, hamming_weight(0x44));
    assert_eq!(2, hamming_weight(0x88));
}