#![allow(dead_code, unused_imports)]

use std::{iter::successors, sync::LazyLock};
static POWER_OF_THREE_TABLE: LazyLock<Vec<i64>> = LazyLock::new(|| {
    successors(Some(1), |prev| Some(prev * 3))
        .take(39)
        // .inspect(|x| {
        //     println!("{x: >19}: {x: >64b}");
        // })
        .collect()
});

struct Solution;
impl Solution {
    pub fn is_power_of_three(n: i32) -> bool {
        if n.is_negative() {
            false
        } else {
            POWER_OF_THREE_TABLE
                .binary_search(&(n as i64))
                .ok()
                .is_some()
        }
    }
}

fn main() {
    use crate::Solution as S;
    [1, 27, 0, -1, -3, 3, 14348907]
        .iter()
        .for_each(|&x| println!("{}", Solution::is_power_of_three(x)));
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
