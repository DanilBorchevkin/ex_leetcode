// Рабочее решение
pub fn remove_element_func(nums: &mut Vec<i32>, val: i32) -> i32 {
    nums.retain(|elem| *elem != val);
    
    return nums.len() as i32;
}

// Решение на копировании
pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
    let nums_old: Vec<i32> = nums.clone();

    nums.clear();

    for elem in &nums_old {
        if *elem != val {
            nums.push(*elem);
        }
    }

    return nums.len() as i32;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn simple_calse() {
        let mut test_vec: Vec<i32> = vec![1,2,3,4,5];
        let to_remove = 5;

        assert_eq!(4, remove_element(&mut test_vec, to_remove));
    }
}
