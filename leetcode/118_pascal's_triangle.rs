#![allow(dead_code, unused_imports)]

struct Solution;
impl Solution {
    pub fn generate(num_rows: i32) -> Vec<Vec<i32>> {
        let num_rows = num_rows as usize;
        let mut ans = Vec::<Vec<i32>>::with_capacity(num_rows);
        ans.push(vec![1]);
        for i in 1..num_rows {
            ans.push(vec![1]);
            for j in 0..(ans[i - 1].len() - 1) {
                let n = ans[i - 1][j] + ans[i - 1][j + 1];
                ans[i].push(n);
            }
            ans[i].push(1);
        }
        ans
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
        assert_eq!(S::generate(5), vec![
            vec![1],
            vec![1,1],
            vec![1,2,1],
            vec![1,3,3,1],
            vec![1,4,6,4,1],
        ])
    }
    #[test]
    fn testcase_2() {
        assert_eq!(S::generate(1), vec![
            vec![1],
        ])
    }
}
