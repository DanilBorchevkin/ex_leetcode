fn length_of_last_word(s: String) -> i32 {
    if s.len() == 0 {
        return 0;
    }

    let (_, last_word) = s
        .trim_end()
        .rsplit_once(' ')
        .unwrap_or((&s.trim_end(), &s.trim_end()));

    last_word.len() as i32
}

fn main() {
    println!(
        "length = {}",
        length_of_last_word(String::from("bbi ssss bbbdf rtertert boom"))
    );
}

#[test]
fn test_empty() {
    let case: String = String::from("");
    assert_eq!(length_of_last_word(case), 0);
}

#[test]
fn test_simple_case() {
    let case: String = String::from("aloga fs da da daa");
    assert_eq!(length_of_last_word(case), 3);
}

#[test]
fn test_simple_spaces_at_end() {
    let case: String = String::from("   fly me   to   the moon  ");
    assert_eq!(length_of_last_word(case), 4);
}

#[test]
fn test_one_char() {
    let case: String = String::from("a");
    assert_eq!(length_of_last_word(case), 1);
}

#[test]
fn test_one_char_with_space() {
    let case: String = String::from("a ");
    assert_eq!(length_of_last_word(case), 1);
}
