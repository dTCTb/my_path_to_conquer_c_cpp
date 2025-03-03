struct Solution;

impl Solution {
    pub fn pivot_array(nums: Vec<i32>, pivot: i32) -> Vec<i32> {
        println!("nums: {:?} | pivot: {}", nums, pivot);
        let ans = Self::my_solve(nums, pivot);
        println!(" ans: {:?}\n", ans);
        ans
    }
    /* 0ms 3.89mb */
    pub fn my_solve(nums: Vec<i32>, pivot: i32) -> Vec<i32> {
        let mut p = 0;
        let (mut l, mut r) = (Vec::with_capacity(nums.len()), Vec::<i32>::new());
        for v in nums.into_iter() {
            match v.cmp(&pivot) {
                std::cmp::Ordering::Less => l.push(v),
                std::cmp::Ordering::Equal => p += 1,
                std::cmp::Ordering::Greater => r.push(v),
            }
        }
        while p > 0 {
            l.push(pivot);
            p -= 1;
        }
        [l, r].concat()
        // l.extend(r); l
    }
}

fn main() {
    Solution::pivot_array(vec![9, 12, 5, 10, 14, 3, 10], 10);
    Solution::pivot_array(vec![-3, 4, 3, 2], 2);
}
