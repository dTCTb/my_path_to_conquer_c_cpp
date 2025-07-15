#![allow(dead_code, unused_imports)]

struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }
}

struct Solution;
impl Solution {
    pub fn get_decimal_value(head: Option<Box<ListNode>>) -> i32 {
        Self::m2(head)
    }
    pub fn m1(head: Option<Box<ListNode>>) -> i32 {
        let mut out: Vec<i32> = Vec::with_capacity(30);
        let mut cur = head.as_ref();
        while let Some(node) = cur {
            out.push(node.val);
            cur = node.next.as_ref();
        }
        out.into_iter()
            .rev()
            .enumerate()
            .fold(0, |acc, (idx, val)| match val {
                0 => acc,
                _ => acc + 2_u32.pow(idx as u32),
            }) as i32
    }
    pub fn m2(head: Option<Box<ListNode>>) -> i32 {
        let mut cur = head.as_ref();
        let mut ans = 0;
        while let Some(node) = cur {
            ans <<= 1;
            if node.val == 1 {
                ans += 1;
            }
            cur = node.next.as_ref();
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
    fn testcases() {}
}
