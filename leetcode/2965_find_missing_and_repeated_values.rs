// BTreeSet 係會有Order，而HashSet 無Order，但呢條LeetCode 兩個嘅Struct 分別不大
use std::collections::HashSet;

struct Solution;

impl Solution {
    /* 0-5ms 2.33mb */
    pub fn find_missing_and_repeated_values(grid: Vec<Vec<i32>>) -> Vec<i32> {
        let n = (grid.len() * grid.len()) as i32;
        let mut set = HashSet::<i32>::new();
        let (mut a, mut b) = (0, 0);
        for row in &grid {
            for col in row {
                match set.insert(*col) {
                    true => (),
                    false => a = *col,
                }
            }
        }
        // println!("{:?}", set);
        for i in 1..=n {
            if !set.contains(&i) {
                b = i;
                break;
            }
        }
        // println!("{:?}", ans);
        vec![a, b]
    }
}

fn main() {
    // let mut a = BTreeSet::from([9, -5, 3]);
    Solution::find_missing_and_repeated_values(vec![vec![1, 3], vec![2, 2]]);
    Solution::find_missing_and_repeated_values(vec![vec![9, 1, 7], vec![8, 9, 2], vec![3, 4, 6]]);
    Solution::find_missing_and_repeated_values(vec![
        vec![1, 2, 3, 4],
        vec![5, 6, 7, 8],
        vec![9, 10, 11, 12],
        vec![13, 14, 15, 15],
    ]);
}
