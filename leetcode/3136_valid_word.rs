#![allow(dead_code, unused_imports)]

struct Solution;
impl Solution {
    /// word constraint: a-zA-Z0-9@#$
    pub fn is_valid(word: String) -> bool {
        if word.len() < 3 {
            return false;
        }
        let mut flags: u8 = 0b00;
        //                    │└ vowel
        //                    └╴ consonant
        for character in word.as_bytes() {
            match character.to_ascii_lowercase() {
                b'a' | b'e' | b'i' | b'o' | b'u' => flags |= 0b01,
                b'a'..=b'z' => flags |= 0b10,
                b'0'..=b'9' => continue,
                _ => return false,
            }
        }
        flags == 0b11
    }
}

fn main() {
    use crate::Solution as S;
    // cargo test --bin <name>
    // cargo eval --test -- path/to/this/file.rs
}

#[rustfmt::skip]
#[cfg(test)]
mod testcases {
    use super::Solution as S;
    #[test]
    #[allow(clippy::bool_assert_comparison)]
    fn testcases() {
        assert_eq!(S::is_valid("234Adas".to_string()), true);
        assert_eq!(S::is_valid("b3".to_string()), false);
        assert_eq!(S::is_valid("a3$e".to_string()), false);
        assert_eq!(S::is_valid("@".to_string()), false);
        assert_eq!(S::is_valid("Aa".to_string()), false);
        assert_eq!(S::is_valid("rrdsUE".to_string()), true);
        assert_eq!(S::is_valid("234Ad$s".to_string()), false);
        assert_eq!(S::is_valid("eB3Aa0e53GAAaE0OB3C3".to_string()), true);
        assert_eq!(S::is_valid("ZBZ3I0CICOGDZDC7OGCC".to_string()), true);
        assert_eq!(S::is_valid("CZ01ZCpzpZ1mBB3537C5".to_string()), false);
        assert_eq!(S::is_valid("Uu1I5eOe6uIa8UoIaeae".to_string()), false);
    }
}
