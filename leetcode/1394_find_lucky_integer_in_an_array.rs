#![allow(dead_code)]

struct Solution;

impl Solution {
    pub fn find_lucky(arr: Vec<i32>) -> i32 {
        Self::m3(arr)
    }
    fn m1(arr: Vec<i32>) -> i32 {
        let mut map = [0i32; 501];
        IntoIterator::into_iter(arr).for_each(|x| map[x as usize] += 1);
        IntoIterator::into_iter(map)
            .enumerate()
            .fold(-1, |max, (k, v)| {
                if k as i32 == v && v != 0 && v > max {
                    v
                } else {
                    max
                }
            })
    }
    fn m2(arr: Vec<i32>) -> i32 {
        use std::collections::HashMap;
        let mut map = HashMap::<i32, i32>::with_capacity(501);
        IntoIterator::into_iter(arr).for_each(|x| *map.entry(x).or_default() += 1);
        IntoIterator::into_iter(map).fold(-1, |max, (k, v)| if k == v && v > max { v } else { max })
    }
    fn m3(arr: Vec<i32>) -> i32 {
        let mut map = [0i32; 501];
        IntoIterator::into_iter(arr).for_each(|x| map[x as usize] += 1);
        IntoIterator::into_iter(map)
            .enumerate()
            .rev()
            .find(|&(i, v)| v != 0 && i as i32 == v)
            .unwrap_or((0, -1))
            .1
    }
}

pub fn main() {
    // cargo eval --test -- path/to/this/file.rs
    // backward compatibility: using full syntax qualified to call
    // IntoIterator::into_iter() instead of .into_iter
}

#[test]
fn testcases() {
    assert_eq!(2, Solution::find_lucky(vec![2, 2, 3, 4]));
    assert_eq!(3, Solution::find_lucky(vec![1, 2, 2, 3, 3, 3]));
    assert_eq!(-1, Solution::find_lucky(vec![2, 2, 2, 3, 3]));
    assert_eq!(2, Solution::find_lucky(vec![1, 2, 2]));
    assert_eq!(3, Solution::find_lucky(vec![2, 1, 2, 3, 4, 3, 5, 4, 3]));
    assert_eq!(4, Solution::find_lucky(vec![3, 4, 3, 4, 3, 4, 2, 4, 2, 1]));
    assert_eq!(
        11,
        Solution::find_lucky(vec![
            1, 2, 2, 10, 30, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11
        ])
    );
    assert_eq!(
        2,
        Solution::find_lucky(vec![
            1, 2, 2, 10, 30, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11
        ])
    );
}
