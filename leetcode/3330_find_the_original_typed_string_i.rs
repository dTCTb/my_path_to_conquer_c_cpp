struct Solution;
impl Solution {
    fn possible_string_count(word: String) -> i32 {
        word.chars()
            .collect::<Vec<_>>()
            .windows(2)
            // .inspect(|x| println!("{x:?}"))
            .fold(0, |ans, win| if win[0] == win[1] { ans + 1 } else { ans })
            + 1
    }
}

fn main() {
    // $cargo eval --test -- path/to/this/file
}

#[cfg(test)]
mod test {
    use super::*;
    #[test]
    fn testcase() {
        // 有件好fun 嘅事，下面個testcase 打少咗個c，搞咗半個鐘先發現...
        assert_eq!(Solution::possible_string_count("abbcccc".to_string()), 5);
        assert_eq!(Solution::possible_string_count("abcd".to_string()), 1);
        assert_eq!(Solution::possible_string_count("aaaa".to_string()), 4);
        assert_eq!(Solution::possible_string_count("ere".to_string()), 1);
        assert_eq!(Solution::possible_string_count("asd".to_string()), 1);
    }
}
