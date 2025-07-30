#![allow(dead_code, unused_imports)]

struct Solution;
impl Solution {
    pub fn longest_subarray(nums: Vec<i32>) -> i32 {
        use std::cmp::Ordering::*;
        nums.chunk_by(|l, r| l == r)
            .fold((0, 0), |(val, cnt), chunk| -> (i32, usize) {
                match chunk[0].cmp(&val) {
                    Equal => (val, cnt.max(chunk.len())),
                    Greater => (chunk[0], chunk.len()),
                    Less => (val, cnt),
                }
            })
            .1 as i32
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
    fn testcase_1() {
        assert_eq!(S::longest_subarray(vec![1,2,3,3,2,2]), 2);
    }
    #[test]
    fn testcase_2() {
        assert_eq!(S::longest_subarray(vec![1,2,3,4]), 1);
    }
    #[test]
    fn testcase_3() {
        assert_eq!(S::longest_subarray(vec![3,3,3,2,3,3]), 3);
    }
    #[test]
    fn testcase_4() {
        assert_eq!(S::longest_subarray(vec![10,10,10,8,8,8,8,12,12,12]), 3);
    }
    #[test]
    fn testcase_5() {
        assert_eq!(S::longest_subarray(vec![1,1,1,1,1,1,2,2]), 2);
    }
    #[test]
    fn testcase_6() {
        assert_eq!(S::longest_subarray(vec![311155,311155,311155,311155,311155,311155,311155,311155,201191,311155]), 8);
    }
    #[test]
    fn testcase_7() {
        assert_eq!(S::longest_subarray(vec![2,1,1,1,1,3,1,1,3,3,3,2,2,2,3,3]), 3);
    }
}
