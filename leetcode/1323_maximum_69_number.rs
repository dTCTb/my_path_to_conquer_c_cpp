#![allow(dead_code, unused_imports)]

struct Solution;
impl Solution {
    pub fn maximum69_number(num: i32) -> i32 {
        match Self::m2(num) {
            Ok(ans) => ans,
            Err(err) => panic!("{}", err.to_string()),
        }
    }
    pub fn m1(num: i32) -> Result<i32, impl std::error::Error> {
        let mut num = num.to_string();
        if let Some(idx) = num.find('6') {
            unsafe { num.as_bytes_mut()[idx] = b'9' }
        };
        num.parse()
    }
    pub fn m2(num: i32) -> Result<i32, impl std::error::Error> {
        num.to_string().replacen("6", "9", 1).parse()
    }
}

fn main() {
    use crate::Solution as S;
    Solution::maximum69_number(9669);
    Solution::maximum69_number(9999);
}
