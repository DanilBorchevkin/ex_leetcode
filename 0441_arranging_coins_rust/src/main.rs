pub fn arrange_coins(n: i32) -> i32 {
    let mut result : i32 = 0;

    if n == 0 {
        return result;
    }

    let mut remain_coins = n;
    let mut next_stairstep_count = 1;

    while (next_stairstep_count <= remain_coins) {
        remain_coins -= next_stairstep_count;
        next_stairstep_count += 1;
        result += 1;
    }

    result
}

fn main() {
    println!("Arange = {}", arrange_coins(10));
}

#[test]
fn test_0() {
    assert_eq!(arrange_coins(0), 0);    
}

#[test]
fn test_n5() {
    assert_eq!(arrange_coins(5), 2);
}

#[test]
fn test_n8() {
    assert_eq!(arrange_coins(8), 3);
}