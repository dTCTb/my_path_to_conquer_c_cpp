struct Solution;

impl Solution {
    pub fn apply_operations(mut nums: Vec<i32>) -> Vec<i32> {
        let mut ans = Vec::new();

        for x in 1..nums.len() {
            nums[x - 1] = if nums[x] == nums[x - 1] {
                nums[x] = 0;
                nums[x - 1] * 2
            } else {
                nums[x - 1]
            };
        }

        for &x in nums.iter() {
            if x > 0 {
                ans.push(x);
            }
        }

        while ans.len() != nums.len() {
            ans.push(0);
        }

        ans
    }
}

fn main() {
    let t1 = Solution::apply_operations(vec![1, 2, 2, 1, 1, 0]);
    println!("{:?}", t1);
    let t2 = Solution::apply_operations(vec![0, 1]);
    println!("{:?}", t2);
}
