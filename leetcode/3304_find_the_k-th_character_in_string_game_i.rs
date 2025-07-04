struct Solution;
impl Solution {
    pub fn kth_character(k: i32) -> char {
        let (k, mut game) = (k as usize, "a".to_string());
        while game.len() < k {
            game.push_str(
                &game
                    .as_bytes()
                    .iter()
                    .map(|&x| if x + 1 > b'z' { 'a' } else { (x + 1) as char })
                    .collect::<String>(),
            )
        }
        game.as_bytes()[k - 1] as char
    }
}
pub fn main() {
    // cargo eval --test -- path/to/this/file
}

#[cfg(test)]
mod test {
    use super::*;
    #[test]
    fn testcases() {
        assert_eq!(Solution::kth_character(5), 'b');
        assert_eq!(Solution::kth_character(10), 'c');
        assert_eq!(Solution::kth_character(100), 'e');
        assert_eq!(Solution::kth_character(499), 'g');
        assert_eq!(Solution::kth_character(1), 'a');
    }
}
