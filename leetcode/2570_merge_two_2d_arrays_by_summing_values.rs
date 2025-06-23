#![allow(dead_code, unused_variables)]
use std::cmp::{max, Ordering};

struct Solution;

impl Solution {
    pub fn merge_arrays(nums1: Vec<Vec<i32>>, nums2: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        Self::solve_3(nums1, nums2)
    }

    /* 1st trial, dump garbage code */
    pub fn solve_1(nums1: Vec<Vec<i32>>, nums2: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let (s1, s2) = (nums1.len(), nums2.len());
        let mut ans = Vec::<Vec<i32>>::new();
        let (mut i1, mut i2) = (0, 0);

        loop {
            if i1 == s1 && i2 == s2 {
                break;
            }
            let c = if i1 < s1 && i2 < s2 {
                nums1[i1][0] - nums2[i2][0]
            } else if i1 < s1 && i2 == s2 {
                -1
            } else {
                1
            };

            if c == 0 {
                ans.push(vec![nums1[i1][0], nums1[i1][1] + nums2[i2][1]]);
                i1 += 1;
                i2 += 1;
            } else if c < 0 {
                ans.push(nums1[i1].clone());
                i1 += 1;
            } else {
                ans.push(nums2[i2].clone());
                i2 += 1;
            }
        }

        ans
    }

    /* slightly enhanced version */
    pub fn solve_2(nums1: Vec<Vec<i32>>, nums2: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let (s1, mut i1, s2, mut i2) = (nums1.len(), 0, nums2.len(), 0);
        let mut ans = Vec::<Vec<i32>>::with_capacity(std::cmp::max(
            nums1.last().unwrap()[1] as usize,
            nums2.last().unwrap()[1] as usize,
        ));

        loop {
            let c = if i1 < s1 && i2 < s2 {
                nums1[i1][0] - nums2[i2][0]
            } else if i1 < s1 && i2 == s2 {
                -1
            } else if i1 == s1 && i2 < s2 {
                1
            } else {
                break;
            };

            match c.cmp(&0) {
                Ordering::Equal => {
                    ans.push(vec![nums1[i1][0], nums1[i1][1] + nums2[i2][1]]);
                    i1 += 1;
                    i2 += 1;
                }
                Ordering::Less => {
                    ans.push(nums1[i1].clone());
                    i1 += 1;
                }
                Ordering::Greater => {
                    ans.push(nums2[i2].clone());
                    i2 += 1;
                }
            }
        }

        ans
    }

    // 0ms 2.44mb rustup!!!! version
    pub fn solve_3(nums1: Vec<Vec<i32>>, nums2: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut ans = Vec::<Vec<i32>>::with_capacity(max(
            nums1.last().unwrap()[1] as usize,
            nums2.last().unwrap()[1] as usize,
        ));
        let (mut n1, mut n2) = (nums1.iter().peekable(), nums2.iter().peekable());

        loop {
            match (n1.peek(), n2.peek()) {
                (Some(c1), Some(c2)) => match (c1[0] - c2[0]).cmp(&0) {
                    Ordering::Equal => {
                        ans.push(vec![c1[0], n1.next().unwrap()[1] + n2.next().unwrap()[1]]);
                    }
                    Ordering::Less => {
                        ans.push(n1.next().unwrap().clone());
                    }
                    Ordering::Greater => {
                        ans.push(n2.next().unwrap().clone());
                    }
                },
                (Some(c1), None) => {
                    for r in n1.by_ref() {
                        ans.push(r.clone());
                    }
                }
                (None, Some(c2)) => {
                    // while let Some(r) = n2.next() {
                    // below recommended by clippy
                    for r in n2.by_ref() {
                        ans.push(r.clone());
                    }
                }
                (None, None) => {
                    break;
                }
            }
        }

        ans
    }
}

fn main() {
    let t1 = <Solution>::merge_arrays(
        vec![vec![1, 2], vec![2, 3], vec![4, 5]],
        vec![vec![1, 4], vec![3, 2], vec![4, 1]],
    );
    println!("{:?}", t1);
    let t2 = Solution::merge_arrays(
        vec![vec![2, 4], vec![3, 6], vec![5, 5]],
        vec![vec![1, 3], vec![4, 3]],
    );
    println!("{:?}", t2);
}
