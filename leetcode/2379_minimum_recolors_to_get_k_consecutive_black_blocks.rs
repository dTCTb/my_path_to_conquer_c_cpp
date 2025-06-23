#![allow(dead_code)]
struct Solution;

impl Solution {
    pub fn minimum_recolors(blocks: String, k: i32) -> i32 {
        let ans = Solution::first(blocks.clone(), k);
        println!("{}, {} | ans: {}", blocks, k, ans);
        ans
    }
    pub fn first(blocks: String, k: i32) -> i32 {
        let mut ans = k;
        blocks
            .chars()
            .map(|x| match x {
                'B' => 1,
                _ => 0,
            })
            .collect::<Vec<i32>>()
            .windows(k as usize)
            .for_each(|x| {
                let diff = k - x.iter().sum::<i32>();
                if diff < ans {
                    ans = diff
                }
                // println!("{:?} -> {:?}", x, x.iter().sum::<i32>());
            });
        // println!("ans: {}", ans);
        ans
    }
    pub fn second(blocks: String, k: i32) -> i32 {
        blocks
            .as_bytes()
            .windows(k as usize)
            .fold(usize::MAX, |acc, win| {
                std::cmp::min(acc, win.iter().filter(|&&n| n != 66).count())
            }) as i32
    }
}

fn main() {
    Solution::minimum_recolors(String::from("WBBWWBBWBW"), 7);
    Solution::minimum_recolors(String::from("WBWBBBW"), 2);
    Solution::minimum_recolors(
        String::from("WWBBBWBWWBWWBBBWWWWWBWBBWBWBWBWBWBWBBBWBW"),
        19,
    );
    Solution::minimum_recolors(
        String::from("WBBBWWWWBBBWBWWBWWWWBWBBWBWWWBWWWWWWBWWWBBWB"),
        34,
    );
    Solution::minimum_recolors(
        String::from(
            "WWBBBWWBBWWBBBBWWWWBWBBWWWBWWBBBBWBWWWWWBBBWBWBBBWBBWWWBWWWWBWWWBWBWWWWBWWBB",
        ),
        6,
    );
    Solution::minimum_recolors(String::from("WBWBWBBWWWWBWBBBWBWBB"), 19);
    Solution::minimum_recolors(String::from("WBBBW"), 4);
    Solution::minimum_recolors(String::from("WWBWBWWBBWBWBWWBWWBWWBBBBWWBBWWWWBBWBWWWBBBBBWBWBWWWWBBWBBBBBWWBBBWBWWWBBBWWWWBBWWBWBB"), 40);
    Solution::minimum_recolors(String::from("B"), 1);
    Solution::minimum_recolors(
        String::from("BBWWWBBWBBBWWWWBBBBWWWWBBWWWBWBWWBBBWWBWWWB"),
        2,
    );
}
