#![allow(dead_code, unused_imports)]

struct Solution;
impl Solution {
    pub fn area_of_max_diagonal(dimensions: Vec<Vec<i32>>) -> i32 {
        let diagonal = |l: i32, w: i32| (l * l + w * w);
        let area = |l: i32, w: i32| l * w;
        let ans = dimensions.iter().fold((0, 0), |(l, w), rec| {
            let cur = diagonal(l, w);
            match diagonal(rec[0], rec[1]) {
                diag if diag == cur => match area(l, w) {
                    a if a > area(rec[0], rec[1]) => (l, w),
                    _ => (rec[0], rec[1]),
                },
                diag if diag > cur => (rec[0], rec[1]),
                _ => (l, w),
            }
        });
        ans.0 * ans.1
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
        assert_eq!(S::area_of_max_diagonal(vec![vec![9,3], vec![8,6]]), 48);
    }
    #[test]
    fn testcase_2() {
        assert_eq!(S::area_of_max_diagonal(vec![vec![3,4], vec![4,3]]), 12);
    }
    #[test]
    fn testcase_3() {
        assert_eq!(S::area_of_max_diagonal(vec![vec![2,6], vec![5,1], vec![3,10], vec![8,4]]), 30);
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
