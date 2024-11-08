pub fn str_str(haystack: String, needle: String) -> i32 {
    let idx = haystack.find(&needle);
    match idx {
        Some(idx) => return idx as i32,
        None => return -1,
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        let haystack = String::from("sadbutsad");
        let needle = String::from("sad");

        assert_eq!(0, str_str(haystack, needle));
    }

    #[test]
    fn not_exist() {
        let haystack = String::from("leetcode");
        let needle = String::from("leeto");

        assert_eq!(-1, str_str(haystack, needle));
    }
}
