#![allow(dead_code, unused_imports)]

struct Solution;
impl Solution {
    pub fn largest_good_integer(num: String) -> String {
        let mut ans = "".to_string();
        num.as_bytes().windows(3).for_each(|win| {
            if win.iter().all(|&x| x == win[0]) && win > ans.as_bytes() {
                ans = String::from_utf8(win.to_owned()).unwrap();
            }
        });
        ans
    }
}

fn main() {
    use crate::Solution as S;
    println!("{}", S::largest_good_integer("6777133339".to_string()));
    println!("{}", S::largest_good_integer("2300019".to_string()));
    println!("{}", S::largest_good_integer("42352338".to_string()));
    println!("{}", S::largest_good_integer("2213".to_string()));
    // cargo test --bin <name>
    // cargo eval --test -- path/to/this/file.rs
}

#[rustfmt::skip]
#[cfg(test)]
mod testcases {
    use super::Solution as S;
    #[test]
    fn testcase_1() {
    }
    #[test]
    fn testcase_2() {
    }
    #[test]
    fn testcase_3() {
    }
    #[test]
    fn testcase_4() {
    }
    #[test]
    fn testcase_5() {
    }
    #[test]
    fn testcase_6() {
    }
    #[test]
    fn testcase_7() {
    }
    #[test]
    fn testcase_8() {
    }
    #[test]
    fn testcase_9() {
    }
    #[test]
    fn testcase_10() {
    }
}
