#![allow(dead_code)]
struct Solution;

impl Solution {
    /* fail to solve with Rust, but capable to solve in C++ */
    pub fn number_of_alternative_groups(colors: Vec<i32>, k: i32) -> i32 {
        Self::tle1(colors, k)
    }

    pub fn tle1(colors: Vec<i32>, k: i32) -> i32 {
        let mut ans = 0;
        let mut arr = colors.clone();
        arr.extend_from_within(..k as usize - 1);
        // println!("{:?}", arr);
        arr.windows(k as usize).for_each(|group| {
            let mut flag = true;
            for i in 1..k as usize {
                if group[i] == group[i - 1] {
                    flag = false;
                    break;
                }
            }
            if flag {
                ans += 1;
            }
        });
        println!("ans: {}", ans);
        ans
    }
    pub fn tle2(colors: Vec<i32>, k: i32) -> i32 {
        let mut ans = 0;
        let mut arr = colors.clone();
        arr.extend_from_within(..k as usize - 1);
        // println!("{:?}", arr);
        let mut win = arr.windows(k as usize);
        loop {
            println!("{:?}", win);
            let mut flag = 0;
            let Some(gp) = win.next() else {
                break;
            };
            for j in 1..k as usize {
                if gp[j] == gp[j - 1] {
                    flag = j;
                    break;
                }
            }
            if flag == 0 {
                ans += 1;
            } else {
                win.nth(flag - 2);
            }
        }
        // println!("ans: {}", ans);
        ans
    }
}

fn main() {
    Solution::number_of_alternative_groups(vec![0, 1, 0, 1, 0], 3);
    Solution::number_of_alternative_groups(vec![0, 1, 0, 0, 1, 0, 1], 6);
    Solution::number_of_alternative_groups(vec![1, 1, 0, 1], 4);
}
