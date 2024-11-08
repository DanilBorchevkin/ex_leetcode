use std::collections::HashMap;

// Working solution
pub fn is_valid(s: String) -> bool {
    if s.len() <= 1 {
        return false
    }

    let mut bracket_stack: Vec<char> = Vec::new();
    let opening: Vec<char> = vec!['(','[','{'];
    let closing: Vec<char> = vec![')', ']', '}'];
    let mut result = true;

    for val in s.chars() {
        if (bracket_stack.len() == 0) && closing.contains(&val) {
            result = false;
            break;
        }

        if opening.contains(&val) {
            bracket_stack.push(val);
            continue;
        }

        if closing.contains(&val) {
            // Check what we close proper bracket. If not - break the cycle and return false
            let idx = closing.iter().position(|&bracket|bracket == val).unwrap();
            if *bracket_stack.last().unwrap() != opening[idx] {
                // We have closing bracket which mismatched with opening
                result = false;
                break;
            }

            bracket_stack.pop();
        }
    }

    // If we have any 
    if bracket_stack.len() != 0 {
        result = false;
    }

    return result;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn simple_case() {
        let test_string = String::from("()");

        assert_eq!(true, is_valid(test_string));
    }

    #[test]
    fn one_unclosed() {
        let test_string = String::from("(");

        assert_eq!(false, is_valid(test_string));
    }

    #[test]
    fn one_bracket_unclosed() {
        let test_string = String::from("(and");

        assert_eq!(false, is_valid(test_string));
    }

    #[test]
    fn all_closed() {
        let test_string = String::from("()[]{}");

        assert_eq!(true, is_valid(test_string));
    }

    #[test]
    fn two_different() {
        let test_string = String::from("[)");

        assert_eq!(false, is_valid(test_string));
    }

    #[test]
    fn two_no_consequence() {
        let test_string = String::from("([)]");

        assert_eq!(false, is_valid(test_string));
    }

    #[test]
    fn starts_with_closed() {
        let test_string = String::from("]()[");

        assert_eq!(false, is_valid(test_string));
    }
}

