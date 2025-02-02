struct Solution;

impl Solution {
    pub fn check(nums: Vec<i32>) -> bool {
        for (i, j) in (0..nums.len() - 1).zip(1..nums.len()) {
            if nums[i] > nums[j] {
                for k in j..nums.len() {
                    if nums[k] > nums[0] || k < nums.len() - 1 && nums[k] > nums[k + 1] {
                        return false;
                    }
                }
            }
        }
        true
    }

    pub fn test(nums: Vec<i32>) {
        println!("{:?} ", nums);
        println!("ans: {}\n", Solution::check(nums));
    }
}

fn main() {
    Solution::test(vec![3, 4, 5, 1, 2]); // true
    Solution::test(vec![2, 1, 3, 4]); // false
    Solution::test(vec![1, 2, 3]); // true
    Solution::test(vec![2, 1]); // true
    Solution::test(vec![2, 4, 1, 3]); // false
    Solution::test(vec![2, 1, 2, 2, 2]); // true
    Solution::test(vec![6, 7, 2, 7, 5]); // false
    Solution::test(vec![7, 9, 1, 1, 1, 3]); // true
    Solution::test(vec![10, 10, 1, 4, 5, 10]); // true
    Solution::test(vec![8, 5, 4, 5, 1, 4, 5, 2, 2]); // testcase 106/109 false
    Solution::test(vec![1, 3, 2]); // testcase 107/109 false
}
