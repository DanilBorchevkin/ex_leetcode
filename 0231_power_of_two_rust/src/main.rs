fn is_power_of_two(n: i32) -> bool {
    if i32::count_ones(n) == 1 {
        return true;
    }

    false
}

fn main() {
    
    println!("Hello, world!, {}", is_power_of_two(2));
}

#[test]
fn test_common() {
    assert_eq!(is_power_of_two(4), true);
    assert_eq!(is_power_of_two(7), false);
}