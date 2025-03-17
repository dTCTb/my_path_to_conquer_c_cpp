struct Solution;

impl Solution {
    pub fn divide_array(nums: Vec<i32>) -> bool {
        Self::rust_style(nums)
    }
    pub fn oop_style(mut nums: Vec<i32>) -> bool {
        nums.sort();
        let mut c = 1_usize;
        for i in 1..nums.len() {
            if nums[i] != nums[i - 1] {
                if c % 2 != 0 {
                    return false;
                } else {
                    c = 0;
                }
            }
            c += 1;
        }
        true
    }

    pub fn rust_style(mut nums: Vec<i32>) -> bool {
        nums.sort();
        // nums.iter().skip(1).fold(nums[0], |acc, x| x - acc) == 0
        nums.chunk_by(|l, r| l == r).all(|c| c.len() % 2 < 1)
    }
}

fn main() {
    println!("{}", Solution::divide_array(vec![3, 2, 3, 2, 2, 2]));
    println!("{}", Solution::divide_array(vec![1, 2, 3, 4]));
}
