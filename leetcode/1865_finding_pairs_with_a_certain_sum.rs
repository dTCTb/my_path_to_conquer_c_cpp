/* [[bin]]
name = "lc_1865_finding_pairs_with_a_certain_sum"
path = "src/lc_1865_finding_pairs_with_a_certain_sum.rs" */

#![allow(dead_code, unused)]
use std::{cell::RefCell, collections::HashMap};

#[derive(Debug)]
struct FindSumPairs {
    nums1: Vec<i32>,
    nums2: RefCell<Vec<i32>>,
    map: RefCell<HashMap<i32, usize>>,
}

impl FindSumPairs {
    fn new(nums1: Vec<i32>, nums2: Vec<i32>) -> Self {
        let map = RefCell::new(HashMap::with_capacity(nums2.len()));
        nums2
            .iter()
            .for_each(|num| *map.borrow_mut().entry(*num).or_default() += 1);
        Self {
            nums1,
            nums2: RefCell::new(nums2),
            map,
        }
    }
    /// when value == 0, left it alone
    /* fn add(&self, index: i32, val: i32) {
        let index = index as usize;
        let old = self.nums2.borrow()[index];
        self.nums2.borrow_mut()[index] += val;
        *self.map.borrow_mut().get_mut(&old).unwrap() -= 1;
        *self
            .map
            .borrow_mut()
            .entry(self.nums2.borrow()[index])
            .or_default() += 1;
    } */
    /// when value == 0, remove the key-value from the HashMap
    fn add(&self, index: i32, val: i32) {
        let index = index as usize;
        let mut nums2 = self.nums2.borrow_mut();
        let mut map = self.map.borrow_mut();
        let old = nums2[index];
        nums2[index] += val;
        let new = nums2[index];

        let _ = *map.entry(new).and_modify(|x| *x += 1).or_default();
        match map.get_mut(&old) {
            Some(v) if *v - 1 == 0 => {
                map.remove(&old);
            }
            Some(v) => *v -= 1,
            None => panic!(),
        }
    }
    fn count(&self, tot: i32) -> i32 {
        self.nums1.iter().fold(0, |acc, &num| {
            self.map.borrow().get(&(tot - num)).unwrap_or(&0) + acc
        }) as i32
    }
}

impl std::fmt::Display for FindSumPairs {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(
            f,
            "nums1: {:?}\nnums2: {:?}\nmap: {:#?}",
            self.nums1,
            self.nums2.borrow(),
            self.map.borrow()
        )
    }
}

pub fn main() {
    // cargo eval --test -- path/to/this/file.rs
    // cargo test --bin lc_1865_finding_pairs_with_a_certain_sum
}

#[test]
fn testcase1() {
    let t1 = FindSumPairs::new(vec![1, 1, 2, 2, 2, 3], vec![1, 4, 5, 2, 5, 4]);
    // println!("{}", t1);
    assert_eq!(8, t1.count(7));
    t1.add(3, 2);
    assert_eq!(2, t1.count(8));
    assert_eq!(1, t1.count(4));
    t1.add(0, 1);
    t1.add(1, 1);
    assert_eq!(11, t1.count(7));
}
