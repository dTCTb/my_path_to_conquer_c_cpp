use std::cmp::Ordering::*;
struct Solution;

const BASE: u32 = 3;

impl Solution {
    pub fn check_powers_of_three(n: i32) -> bool {
        Self::enum_pow(BASE, n as u32) == 0
    }

    /* 0ms 2.32mb */
    pub fn enum_pow(base: u32, mut limit: u32) -> u32 {
        let mut arr = vec![1];
        while arr.last().unwrap() <= &limit {
            arr.push(arr.last().unwrap() * base);
        }
        // print!("{:?} | ", arr);
        arr.into_iter().rev().for_each(|e| {
            if let Equal | Greater = limit.cmp(&e) {
                limit -= e;
            }
        });
        limit
    }

    pub fn test(n: i32) {
        print!("{} | ", n);
        let ans = Solution::check_powers_of_three(n);
        println!("{}", ans);
    }
}

fn main() {
    Solution::test(12);
    Solution::test(91);
    Solution::test(21);
    Solution::test(82);
    Solution::test(27);
}
