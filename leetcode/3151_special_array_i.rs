struct Solution;

impl Solution {
    pub fn is_array_special(nums: Vec<i32>) -> bool {
        // for i in 1..nums.len() {
        for (i, j) in (0..nums.len() - 1).zip(1..nums.len()) {
            if nums[i] % 2 == nums[/* i - 1 */j] % 2 {
                return false;
            };
        }
        true
    }
}

pub fn main() {
    println!("{}", Solution::is_array_special(vec![1])); // true
    println!("{}", Solution::is_array_special(vec![2, 1, 4])); // true
    println!("{}", Solution::is_array_special(vec![4, 3, 1, 6])); // false
}
