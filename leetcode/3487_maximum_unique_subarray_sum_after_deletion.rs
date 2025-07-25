#![allow(dead_code, unused_imports)]

struct Solution;
const OFFSET: i32 = 100;
impl Solution {
    pub fn max_sum(mut nums: Vec<i32>) -> i32 {
        let mut seen = [0; 201];
        nums.sort_unstable_by(|l, r| r.cmp(l));
        seen[(nums[0] + OFFSET) as usize] += 1;

        nums.iter().fold(nums[0], |ans, &val| {
            seen[(val + 100) as usize] += 1;
            if seen[(val + OFFSET) as usize] > 1 || ans + val < ans {
                ans
            } else {
                ans + val
            }
        })
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
    fn unique_and_all_positive() {
        assert_eq!(15, S::max_sum(vec![1, 2, 3, 4, 5]));
    }
    #[test]
    fn many_1_and_one_0() {
        assert_eq!( 1, S::max_sum(vec![1, 1, 0, 1, 1]));
    }
    #[test]
    fn range_from_neg2_to_2() {
        assert_eq!( 3, S::max_sum(vec![1, 2, -1, -2, 1, 0, -1]));
    }
    #[test]
    fn only_one_0() {
        assert_eq!( 0, S::max_sum(vec![0]));
    }
    #[test]
    fn only_one_neg1() {
        assert_eq!(-1, S::max_sum(vec![-1]));
    }
    #[test]
    fn duplicate_positive_and_negative() {
        assert_eq!(18, S::max_sum(vec![6, 4, 6, 1, 4, 2, -2, -7, 5, -6]));
        assert_eq!(19, S::max_sum(vec![-6, 8, -6, 8, -10, -3, 4, -7, 1, 6]));
    }
    #[test]
    fn unique_positive_and_negative() {
        assert_eq!(18, S::max_sum(vec![0, 3, -10, -9, 6, -9, 2, 7, -2, -8]));
    }
    #[test]
    fn all_negative_and_one_zero() {
        assert_eq!( 0, S::max_sum(vec![-7, -6, -6, -6, 0, -4, -8, -3, -2, -7]));
    }
}
