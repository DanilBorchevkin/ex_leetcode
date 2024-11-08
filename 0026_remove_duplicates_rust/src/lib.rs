pub fn remove_duplicates_old(nums: &mut Vec<i32>) -> i32 {
    // Handle simple cases
    if nums.len() <= 1 {
        return nums.len() as i32;
    }
    
    // Начинаем со второго
    // Если текущее значение равно предыдущему, 
    // то удаляем значение с текущим индексом
    // Если не равно, не удаляем.

    let mut idx: usize = 1;
    let mut max_idx: usize = nums.len();

    while idx < max_idx {
        while (idx < nums.len()) && (nums[idx] == nums[idx - 1]) {
            _ = nums.remove(idx);
        }

        max_idx = nums.len();

        idx += 1;
    }

    let res = nums.len() as i32;

    return res;
}

pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
    // Handle simple cases
    if nums.len() <= 1 {
        return nums.len() as i32;
    }
    
    // 1. Копируем вектор nums в новый вектор orig_nums
    // 2. Очищаем вектор nums - clear
    // 3. В цикле с нулевого элекмента пушим элементы
    //   - Если новый элемент равен предыдущему, просто увеличием счетчик
    //   - Если не равен, то пушим в конец nums и увеличиваем счетчик

    let orig_nums = nums.clone();

    nums.clear();

    // Добавляем первый элемент. У нас длина больше единицы.
    nums.push(orig_nums[0]);

    for idx in 1 .. orig_nums.len() {
        if orig_nums[idx] != orig_nums[idx-1] {
            nums.push(orig_nums[idx])
        }
    }

    let res = nums.len() as i32;
    return res;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_len_1() {
        let mut test_vec: Vec<i32> = vec![1]; 
        
        let result = remove_duplicates(&mut test_vec);
        assert_eq!(result, 1);
        assert_eq!(test_vec, vec![1]);
    }

    #[test]
    fn test_len_2_doubling() {
        let mut test_vec: Vec<i32> = vec![1,1]; 
        
        let result = remove_duplicates(&mut test_vec);
        assert_eq!(result, 1);
        assert_eq!(test_vec, vec![1]);
    }

    #[test]
    fn test_simple_case() {
        let mut test_vec: Vec<i32> = vec![1,1,2]; 
        
        let result = remove_duplicates(&mut test_vec);
        assert_eq!(result, 2);
        assert_eq!(test_vec, vec![1,2]);
    }

    #[test]
    fn test_simple_case_with_doubling() {
        let mut test_vec: Vec<i32> = vec![1,1,1,2]; 
        
        let result = remove_duplicates(&mut test_vec);
        assert_eq!(result, 2);
        assert_eq!(test_vec, vec![1,2]);
    }

    #[test]
    fn test_complex() {
        let mut test_vec: Vec<i32> = vec![0,0,1,1,1,2,2,3,3,4]; 
        
        let result = remove_duplicates(&mut test_vec);
        assert_eq!(result, 5);
        assert_eq!(test_vec, vec![0,1,2,3,4]);
    }
}
