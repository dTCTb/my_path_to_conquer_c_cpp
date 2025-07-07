#![allow(dead_code)]

use std::{
    cmp::{Ordering::*, Reverse},
    collections::BinaryHeap,
};

struct Solution;
impl Solution {
    pub fn max_events(events: Vec<Vec<i32>>) -> i32 {
        // Self::max_events_1(events)
        Self::max_events_2(events)
    }
    #[rustfmt::skip]
    pub fn max_events_1(events: Vec<Vec<i32>>) -> i32 {
        let mut heap = BinaryHeap::with_capacity(events.len());
        events
            .into_iter()
            .for_each(|event| heap.push(Reverse(event)));
        Self::heap_pop(&heap);
        let (mut day, mut ans) = (1, 0);
        while let Some(event) = heap.peek() {
            let [start_day, end_day] = event.0[..] else { panic!(); };
            match day.cmp(&start_day) {
                Equal | Greater => {
                    if day <= end_day { ans += 1; }
                    heap.pop();
                }
                Less => while day < start_day { day += 1; }
            }
            day += 1;
        }
        ans
    }
    pub fn max_events_2(mut events: Vec<Vec<i32>>) -> i32 {
        events.sort_by(|a, b| a[0].cmp(&b[0]));
        let max_day = events.iter().map(|e| e[1]).max().unwrap_or(0);
        let mut heap = BinaryHeap::with_capacity(events.len());
        let (mut ans, mut j) = (0, 0);
        (1..=max_day).for_each(|i| {
            while j < events.len() && events[j][0] <= i {
                heap.push(Reverse(events[j][1]));
                j += 1;
            }
            while let Some(&Reverse(end)) = heap.peek() {
                if end < i {
                    heap.pop();
                } else {
                    break;
                }
            }
            if let Some(Reverse(_)) = heap.pop() {
                ans += 1;
            }
        });
        ans
    }
    fn heap_pop(heap: &BinaryHeap<Reverse<Vec<i32>>>) {
        let mut heap = heap.clone();
        while let Some(top) = heap.pop() {
            println!("{top:?}");
        }
    }
}

#[allow(unused_imports)]
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
    fn example_1() {
        assert_eq!(
            S::max_events(vec![vec![1, 2], vec![2, 3], vec![3, 4]]),
            3
        );
    }
    #[test]
    fn example_2() {
        assert_eq!(
            S::max_events(vec![vec![1, 2], vec![2, 3], vec![3, 4], vec![1, 2]]),
            4
        );
    }
    #[test]
    fn maximum_overlapping_events() {
        assert_eq!(
            S::max_events(vec![vec![1, 10], vec![1, 10], vec![1, 10], vec![1, 10]]),
            4
        );
    }
    #[test]
    fn large_range_of_days() {
        assert_eq!(
            S::max_events(vec!(vec![1, 100], vec![50, 100], vec![60, 70], vec![90, 95])),
            4
        );
    }
    #[test]
    fn single_day_events() {
        assert_eq!(
            S::max_events(vec!(vec![1, 1], vec![2, 2], vec![3, 3], vec![4, 4])),
            4
        );
    }
    #[test]
    fn events_with_same_end_day() {
        assert_eq!(
            S::max_events(vec!(vec![1, 2], vec![2, 2], vec![1, 2], vec![1, 2])),
            2
        );
    }
    #[test]
    fn no_overlapping_events() {
        assert_eq!(
            S::max_events(vec!(vec![1, 2], vec![3, 4], vec![5, 6])),
            3
        );
    }
    #[test]
    fn events_with_disjoint_time_intervals() {
        assert_eq!(
            S::max_events(vec!(vec![1, 2], vec![4, 5], vec![7, 8], vec![10, 11])),
            4
        );
    }
    #[test]
    fn all_events_on_same_day() {
        assert_eq!(
            S::max_events(vec!(vec![1, 1], vec![1, 1], vec![1, 1], vec![1, 1])),
            1
        );
    }
    #[test]
    fn early_start_late_end() {
        assert_eq!(
            S::max_events(vec!( vec![1, 3], vec![2, 4], vec![3, 5], vec![4, 6], vec![5, 7])),
            5
        );
    }
    #[test]
    fn completely_overlapping_events() {
        assert_eq!(
            S::max_events(vec!(vec![1, 3], vec![1, 3], vec![1, 3], vec![1, 3])),
            3
        );
    }
    #[test]
    fn events_with_random_intervals() {
        assert_eq!(
            S::max_events(vec!( vec![1, 3], vec![5, 8], vec![6, 10], vec![9, 11], vec![12, 15])),
            5
        );
    }
    #[test]
    fn testcase_27() {
        assert_eq!(
            S::max_events(vec!( vec![1, 4], vec![4, 4], vec![2, 2], vec![3, 4], vec![1, 1])),
            4
        );
    }
    #[test]
    fn important_testcase() {
        assert_eq!(
            S::max_events(vec!( vec![1, 2], vec![1, 2], vec![3, 3], vec![1, 5], vec![1, 5])),
            5
        );
    }
}
