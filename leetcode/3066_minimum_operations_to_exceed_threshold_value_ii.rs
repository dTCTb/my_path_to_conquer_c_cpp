#![allow(dead_code)]
use std::{cmp::Reverse, collections::BinaryHeap};

struct Solution;

impl Solution {
    pub fn min_operations(nums: Vec<i32>, k: i32) -> i32 {
        Solution::learn_new_thing(nums, k)
    }

    pub fn learn_new_thing(nums: Vec<i32>, k: i32) -> i32 {
        let mut nums: BinaryHeap<_> = nums.into_iter().map(|num| Reverse(num as u64)).collect();

        let mut count = 0;
        while let (Some(Reverse(small)), Some(mut large)) = (
            nums.pop().filter(|&Reverse(num)| num < k as u64),
            nums.peek_mut(),
        ) {
            large.0 += small * 2;
            count += 1;
        }
        count
    }
}

pub fn main() {
    Solution::min_operations(vec![2, 11, 10, 1, 3], 10);
    Solution::min_operations(vec![1, 1, 2, 4, 9], 20);
}
