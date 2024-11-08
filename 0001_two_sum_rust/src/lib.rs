pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
    let mut result : Vec<i32> = [0, 1].to_vec();

    // Works solution but try to improve it
    // Exclude las element
    for idx_1 in 0..nums.len() - 1 {
        for idx_2 in 1..nums.len() {
            if (nums[idx_1] + nums[idx_2]) == target {
                result[0] = idx_1 as i32;
                result[1] = idx_2 as i32;
                break;
            }
        }
    }

    return result;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn two_zero() {
        let result = two_sum([0,0].to_vec(), 0);
        assert_eq!(result[0], 0);
        assert_eq!(result[1], 1);
    }

    #[test]
    fn two_non_zero() {
        let result = two_sum([3, 5].to_vec(), 8);
        assert_eq!(result[0], 0);
        assert_eq!(result[1], 1);
    }

    #[test]
    fn three_non_zero() {
        let result = two_sum([3, 5, 4].to_vec(), 9);
        assert_eq!(result[0], 1);
        assert_eq!(result[1], 2);
    }

    #[test]
    fn several_negative() {
        let result = two_sum([-5, -5, 3, 8 , 12].to_vec(), -2);
        assert_eq!(result[0], 1);
        assert_eq!(result[1], 2);
    }

    #[test]
    fn all_negative() {
        let result = two_sum([-1,-2,-3,-4,-5].to_vec(), -8);
        assert_eq!(result[0], 2);
        assert_eq!(result[1], 4);
    }
}
